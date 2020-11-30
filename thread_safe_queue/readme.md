# 线程安全队列

这一章还蛮难的orz  
由于并发编程经验匮乏，碰到时就是凭感觉瞎写，开头那堆方法论暂时是吃不透了  
写 <i>仿muduo的http服务器</i> 的时候，线程池里需要一个并发安全的生产者-消费者队列  
然而实现得非常粗糙就是挂一把锁+条件变量  
大概长这个样子:
```
template <typename T>
class LockBasedThreadSafeQueue {
public:
    LockBasedThreadSafeQueue(){}
    void push(T val){
        unique_lock<mutex> lk(queueLock_);
        queue_.push(move(val));
        queueCond_.notify_one();
    }
    shared_ptr<T> wait_pop(){
        unique_lock<mutex> lk(queueLock_);
        while (queue_.empty()){
            queueCond_.wait(lk);
        }
        shared_ptr<T> sp(make_shared<T>(move(queue_.front())));
        queue_.pop();
        return sp;
    }
private:
    mutex queueLock_;
    condition_variable queueCond_;
    queue<T> queue_;
};
```

## 来尝试把锁的粒度变细
* 一个小的优化点是用share_ptr替代原来的数据  
好处是:
```
void push(T val){
    unique_lock<mutex> lk(queueLock_);
    queue_.push(move(val));
    queueCond_.notify_one();
}
```
变成了
```
void push(T val){
    shared_ptr<T> data(make_shared<T>(move(val)));
    unique_lock<mutex> lk(queueLock_);
    queue_.push(data);
    queueCond_.notify_one();
}
```
新实例的内存分配可以在mutex外完成

* 用自己实现的队列代替std::queue（基于链表）  
想要继续优化这个队列，发现已经无从下手了，原因是std::queue做了太多的工作  
要继续减小粒度，只能先把这些操作拆出来  

比较简单的队列是实现是用一个单链表，并关心它的head和tail指针  
同时也有一个显而易见的好处是，插入一个结点可以预先分配，并且原子地修改指针  
先来看看这样的实现有没有什么风险:
```
void push(T t){
    Node* new_node = new Node(t);
    if (tail){
        tail->next = new_node;
    } else {
        head = new_node;
    }
    tail = tail->next;
}

shared_ptr<T> pop(){
    if (!head){
        return shared_ptr<T>();
    }
    shared_ptr<T> res(move(head->data));
    head = head->next;
    return res;
}
```
1. push()可能修改head或者tail
2. push()和pop()除了访问head和tail, 还都需要head->next和tail->next, 非常容易同时访问head和tail

* 解决: 虚拟结点  
参考一下迭代器的实现: tail不是指向最后一个元素，而是指向当前最后一个元素的后一个元素，也就是下一个新结点应该放置的位置  
如果事先做好这个虚拟结点，push首先不会直接修改head了  
队列为空的情况下，head==tail，这个还是要判断，但也只有一个判断需要对tail加锁，并且一定是先锁head再锁tail
```
template <typename T>
class LinkedListQueue {
private:
    struct Node {
        Node(){}
        explicit Node(T value): data(move(value)){}
        unique_ptr<Node> next;
        shared_ptr<T> data;
    };
    mutex head_lock;
    mutex tail_lock;
    unique_ptr<Node> head;
    Node* tail;

private:
    Node* get_tail(){
        lock_guard<mutex> lk(tail_lock);
        return tail;
    }
    unique_ptr<Node> pop_head(){
        lock_guard<mutex> lk(head_lock);
        if (head.get() == get_tail()) {
            return nullptr;
        }
        unique_ptr<Node> old_head = move(head);
        head = move(old_head->next);
        return old_head;
    }

public:
    LinkedListQueue(): head(new Node), tail(head.get()){}
    void push(T t){
        shared_ptr<T> new_data(make_shared<T>(move(t)));
        unique_ptr<Node> p(new Node);
        Node* new_tail = p.get();

        lock_guard<mutex> lk(tail_lock);
        tail->data = new_data;
        tail->next = move(p);
        tail = new_tail;
    }
    shared_ptr<T> try_pop(){
        unique_ptr<Node> old_head = pop_head();
        return old_head ? old_head->data : shared_ptr<T>();
    }
};
```
比起最初的版本，现在:
1. 尽可能在锁外进行资源分配
2. push和pop在大多数情况下可以并发执行

TODO: 
有界队列和无锁队列

[参考资料]  
C++ Concurrency in Action 第六章