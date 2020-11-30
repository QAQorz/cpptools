#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <memory>
using namespace std;

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

int main() {
    LinkedListQueue<int> queue;

    thread t([&queue]{
        for (int i = 1; i < 100; i++) {
            cout << "add " << i << endl;
            queue.push(i);
        }
    });
    thread t2([&queue]{
        while (1){
            shared_ptr<int> res = queue.try_pop();
            if (res){
                cout << "pop " << *res << endl;
            }
        }
    });
    t.join();
    t2.join();
    return 0;
}
