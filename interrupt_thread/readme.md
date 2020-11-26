# 怎样停止一个正在运行的线程
* 为什么需要中断  
可能是线程运行时间太长，或者取消了这个任务

* 谁来开启这个中断  
显然不能是这个线程自己，但是线程是共享的，同一个进程下的其他线程也许可以

需要一个与线程绑定的interrupt flag标志位  

* 为什么标志位需要设置为thread local  
每个task func要检查"当前线程的flag标志"

* 设置标志位之后怎么使之生效  
本来想的是难道检查标志break出去？
书里给出的办法是
```
void interruption_point(){
	if (this_thread_interrupt_flag.is_set()){
		throw thread_interrupted();
	}
}
```  
抛出一个异常，中断之后需要做的事可以写在catch里  
这操作我真想不到，从来没用过C++的异常

于是可以写一个简单版本
```
class InterruptFlag{
public:
    InterruptFlag(): flag_(false){}
    void set(){
        flag_ = true;
    }
    bool is_set(){
        return flag_;
    }
private:
    atomic<bool> flag_;
};
thread_local InterruptFlag flag;

class Thread {
public:
    Thread(const function<void ()>& func){
        promise<InterruptFlag*> p;
        t = thread([func, &p]{
            p.set_value(&flag);
            try {
                func();
            } catch (exception&) {
                cout << "interrupt" << endl;
            }
        });
        this_thread_interrupt_flag = p.get_future().get();
    }
    void interrupt(){
        if (this_thread_interrupt_flag){
            cout << "flag set" << endl;
            this_thread_interrupt_flag->set();
        }
    }

    void join(){
        t.join();
    }
private:
    thread t;
    InterruptFlag* this_thread_interrupt_flag;
};

void interrupt_point(){
    cout << "check flag" << endl;
    if (flag.is_set()){
        throw exception();
    }
}

void thread_func(){
    for (int i = 1; i < 10; i++){
        interrupt_point();
        cout << i << endl;
        sleep(1);
    }
}

int main() {
    Thread t(thread_func);
    sleep(2);
    t.interrupt();
    t.join();
    return 0;
}
```

TODO: 中断等待

[参考资料]  
C++ Concurrency in Action