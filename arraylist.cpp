#include "arraylist.h"
#define min(x, y) ((x<y)?(x):(y))

ArrayList::ArrayList() {
    MAXSIZE = 5;
    sz = 0;
    arr = new int[MAXSIZE];
}

ArrayList::ArrayList(unsigned maxsize) {
    MAXSIZE = maxsize;
    sz = 0;
    arr = new int[MAXSIZE];
}

ArrayList::ArrayList(const ArrayList& v) {
    sz = v.sz;
    MAXSIZE = v.sz*2;
    arr = new int[MAXSIZE];
    for (int i = 0; i < v.sz; i++) arr[i] = v.arr[i];
}

ArrayList::~ArrayList() {
    delete[] arr;
    arr = nullptr;
}

int& ArrayList::operator[](unsigned index) {
    return arr[index];
}

unsigned ArrayList::size() {
    return sz;
}

bool ArrayList::empty() {
    return sz == 0;
}

void ArrayList::resize(unsigned new_size) {
    MAXSIZE = new_size*2;
    int* new_arr = new int[MAXSIZE];
    for (unsigned i = 0; i < min(sz, new_size); i++) new_arr[i] = arr[i];
    sz = new_size;
    delete[] arr;
    arr = new_arr;
}

void ArrayList::push_back(int x) {
    if (sz == MAXSIZE){
        resize(MAXSIZE*2);
    }
    arr[sz++] = x;
}

void ArrayList::pop_back() {
    if (sz) arr[sz--] = 0;
}

void ArrayList::clear() {
    sz = 0;
    MAXSIZE = 5;
    delete[] arr;
    arr = nullptr;
}