#ifndef __BINARY_HEAP_H
#define __BINARY_HEAP_H

#include <cstdio>

template <typename T>
class binary_heap{
private:
    T* heap;
    size_t sz = 0;
    size_t MAXSIZE = 5;
    void swap(T& a, T& b){
        T c(a);
        a = b;
        b = c;
    }
public:
    binary_heap<>(){
        heap = new T[MAXSIZE];
    }
    size_t size(){
        return sz;
    }
    T top(){
        return heap[0];
    }
    T back(){
        return heap[sz-1];
    }
    bool empty(){
        return sz == 0;
    }
    void push(T t){
        heap[++sz] = t;
        size_t cur = sz;
        while (cur && heap[cur] < heap[cur>>1]){
            swap(heap[cur] < heap[cur>>1]);
            cur >>= 1;
        }
    }
    void pop(){
        swap(top(), back());
        --sz;
        int cur = 1;
        while ((cur<<1) <= sz){
            int left = cur<<1;
            if (left+1 <= sz && heap[left+1] < heap[left]) left++;
            if (heap[left] >= heap[cur]) break;
            swap(heap[left], heap[cur]);
            cur = left;
        }
    }
};

#endif
