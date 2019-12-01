#ifndef _ABSTRACT_LIST_H
#define _ABSTRACT_LIST_H

typedef void * ADT;
typedef const void * CADT;
typedef int (*COMPARE_OBJECT)(CADT e1, CADT e2);
typedef void (*DESTROY_OBJECT)(ADT e);
typedef void (*MANIPULATE_OBJECT)(ADT e, ADT tag);

struct ListNode{
    ADT data;
    ListNode *pre, *next;
    ListNode(){
        data = nullptr;
        pre = next = nullptr;
    }
    explicit ListNode(ADT d){
        data = d;
        pre = next = nullptr;
    }
};
typedef ListNode* PList;

class AbstractList{
public:
    AbstractList();

    void append(ADT);
    void insert(ADT, unsigned);
    void remove(unsigned);
    void clear();
    void traverse(MANIPULATE_OBJECT, ADT);
    bool search(ADT, COMPARE_OBJECT);
    unsigned get_count();
    bool empty();

private:
    PList head, tail;
    unsigned len;
    void add(PList, ADT);
    void del(PList);
};



#endif