#include <iostream>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <functional>
#include <unistd.h>
#include <future>

using namespace std;

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