#include <iostream>
#include "intSLList.h"

IntSLList::~IntSLList(){
    for(IntSLLNode *p; !isEmpty();){
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(int el){
    //******************************
    head = new IntSLLNode(el, head);
    if(tail == 0)
        tail = head;
}

void IntSLList::addToTail(int el){
    if(tail != 0){
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    }
    else
        head = tail = new InrSLLNode(el);
}

int IntSLList::deleteFromHead(){
    int el = head->info;
    IntSLLNode *tem = head;
    if(head == tail)
        head = tail = 0;
    else
        head = head->next;
    delete tem;
    return el;
}

int IntSLList::deleteFromTail(){
    int el = tail->info;
    if(head == tail){
        delete head;
        head = tail = 0;
    }
    else{
        IntSLLNode *tem;
        //find the tail
        for(tem=head; tem->next!=tail;tem=tem->next);
        delete tail;
        tail = tem;
        tail->next = 0;
    }
    return el;
}

void IntSLList::deleteNode(int el)(){
    if(head != 0){
        if(head == tail && el == head->info){
            delete head;
            head = tail = 0;
        }
        else if(el == head->info){
            IntSLLNode *tem = head;
            head = head->next;
            delete tem;
        }
        else{
            IntSLLNode *pred, 8tem;
            for(pred=head, tem=head->next; tem!=0&&!(tem->info==el); pred=pred->next, tem=tem->next);
            if(tem != 0){
                pred->next = tem->next;
                if(tem == tail)
                    tail = pred;
                delete tem;
            }
        }
    }
}

//search the element
bool IntSLList::isInList(int el) const{
    IntSLLNode *temp;
    for(tem=head; tem!=0&&!(tem->info==el); tem=tem->next);
    return tem != 0;
}
