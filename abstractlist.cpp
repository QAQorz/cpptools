#include "abstractlist.h"

AbstractList::AbstractList() {
    len = 0;
    head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    tail->pre = head;
}

void AbstractList::add(PList cur, ADT e) {
    PList new_node = new ListNode(e);
    new_node->next = cur->next;
    cur->next->pre = new_node;
    new_node->pre = cur;
    cur->next = new_node;
}

void AbstractList::append(ADT e) {
    add(tail, e);
}

void AbstractList::insert(ADT e, unsigned i) {
    int pos = 0;
    for (PList now = head; now != tail; now = now->next){
        if (pos == i){
            add(now, e);
            break;
        }
        pos++;
    }
}

void AbstractList::del(PList cur) {
    PList pr = cur->pre;
    PList nxt = cur->next;
    pr->next = nxt;
    nxt->pre = pr;
    delete cur;
}

void AbstractList::remove(unsigned i) {
    int pos = 0;
    for (PList now = head; now != tail; now = now->next){
        if (pos == i){
            del(now);
            break;
        }
        pos++;
    }
}

void AbstractList::clear() {
    while (tail->pre != head){
        PList cur = tail;
        tail = tail->pre;
        delete cur;
    }
}

void AbstractList::traverse(MANIPULATE_OBJECT manipulate, ADT tag) {
    for (PList now = head; now != tail; now = now->next){
        (*manipulate)(now->data, tag);
    }
}

bool AbstractList::search(ADT e, COMPARE_OBJECT cmp) {
    for (PList now = head->next; now != tail; now = now->next){
        if ((*cmp)(e, now->data)) return true;
    }
    return false;
}

unsigned AbstractList::get_count() {
    return len;
}

bool AbstractList::empty() {
    return (head->next == tail && tail->pre == head);
}
