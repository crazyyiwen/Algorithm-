//*******************intSLList.h*************************
//         single-linked lsit class to store integers
#ifndef INT_LINKED_LIST
#DEFINE INT_LINKED_LIST

class IntSLLNode{
public:
    IntSLLNode(){
        next = 0;
    }
    IntSLLNode(int el, IntSLLNode *ptr = 0){
        info = el;
        next = ptr;
    }
public:
    int info;
    IntSLLNode *next;
};
class IntSLList{
public:
    IntSLList(){
        head = tail = 0;
    }
    ~IntSLList();
    int isEmpty(){
        return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
private:
    IntSLLNode *head, *tail;
};

#endif
