/*
 * Assignment_2 programmed by Yiwen Zhao
 * stack FILO
 *
 */
#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
using namespace std;

template<typename T>
class Node{
public:
    //construct
    Node(){
        next = prev = NULL;
    }
    //construct
    Node(const T &element, Node *n = NULL, Node *p = NULL){
        info = element;
        next = n;
        prev = p;
    }
public:
    T info;
    Node<T> *next, *prev;
};

template<typename T>
class DLinkedListADT{
public:
    //construct
    DLinkedListADT(){
        m_count = 0;
        head = tail = NULL;
    }
    void addFirst(const T &element);
    T deleteFirst();
    int countSize();
    bool isEmpty();
    void printNextList();
    void printPrevList();
protected:
    int m_count;
    Node<T> *head, *tail;
};
// the size of list
template<typename T>
int DLinkedListADT<T>::countSize(){
    return m_count;
}
// is list empty or not
template<typename T>
bool DLinkedListADT<T>::isEmpty(){
    return m_count == 0;
}
// add element to beginning of the list
template<typename T>
void DLinkedListADT<T>::addFirst(const T &element){
    Node<T> *tmp = new Node<T>(element);
    // no elements so make head and tail point to new node
    if(head == NULL){
        head = tmp;
        tail = head;
    }
    else{
        tmp->next = head;     //connect new elem next to a head
        head->prev = tmp;    //connect head elem prev to tmp
        head = tmp;           //elem tmp as head
    }
    m_count++;                 //increment size by 1
}

//delete first element and return its value
template<typename T>
T DLinkedListADT<T>::deleteFirst(){
    if(head == NULL){
        cout<<"empty list!"<<endl;
        return -1;
    }
    //delete first node(only one node in the list)
    else if(head == tail && head != NULL && tail->next == NULL){
        int el = head->info;
        delete head;
        head = tail = NULL;
        return el;
        m_count--;
    }
    //delete first node
    else{
        int el = head->info;
        head = head->next;
        delete head->prev;
        head->prev = NULL;
        m_count--;
        return el;
    }
}

//print list from first to last
template<typename T>
void DLinkedListADT<T>::printNextList(){
    Node<T> *n = head;
    while(n != NULL){
        cout<<n->info<<" ";
        n = n->next;
    }
}
//print list from last to first
template<typename T>
void DLinkedListADT<T>::printPrevList(){
    Node<T> *n = tail;
    while(n != NULL){
        cout<<n->info<<" ";
        n = n->prev;
    }
}
#endif // DOUBLE_LINKED_LIST

