/*
 * Assignment_2 programmed by Yiwen Zhao
 * 1 creating double Linked List
 * 2 inserting a new node before or after or at the middle of the list
 * 3 deleting the first node in the list where the data matches num
 * 4 traversing the List from first to last or from last to first
 * 5 counting the size of the list
 * 6 testing the code
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
    void addLast(const T &element);
    void addMiddle(int p, const T &element);
    T deleteFirstInstance(const T &element);
    T deleteFirst();
    T deleteLast();
    int countSize();
    bool isEmpty();
    void printNextList();
    void printPrevList();
    //int m_count;
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
        head->prev = tmp;     //connect head elem prev to tmp
        head = tmp;           //elem tmp as head
    }
    m_count++;                //increment size by 1
}
//add element to the end of the list
template<typename T>
void DLinkedListADT<T>::addLast(const T &element){
    Node<T> *tmp = new Node<T>(element);
    if(head == NULL){
        head = tmp;
        tail = head;
    }
    else{
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
    m_count++;
}
// add element to the middle of the list
template<typename T>
void DLinkedListADT<T>::addMiddle(int p, const T &element){

    if(p == 1 || p == (m_count+1)){
        if(p == 1){
            addFirst(element);    //warning: before el no const T&
        }
        else{
            addLast(element);     //warning: before el no const T&
        }
    }
    else if(p < 1 || p > (m_count+1)){
        cout<<"the position you want to insert is out of boundary!"<<endl;
        cout<<"please try it again!"<<endl;
        return;
    }
    else{
        Node<T> *tmp = new Node<T>(element);
        Node<T> *t = new Node<T>();
        t = head;
        for(int i=1; i<(p-1); i++){
            t = t->next;
        }
        tmp->next = t->next;
        t->next->prev = tmp;
        t->next = tmp;
        tmp->prev = t;
        m_count++;
        //delete t;
    }
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
//delete last element and return its value
template<typename T>
T DLinkedListADT<T>::deleteLast(){
    if(head == NULL){
        cout<<"empty list!"<<endl;
        return -1;
    }
    //delete last node(only one node in the list)
    else if(head == tail && head != NULL && tail->next == NULL){
        int el = head->info;
        delete head;
        head = tail = NULL;
        m_count--;
        return el;
    }
    //delete last node
    else{
        int el = tail->info;
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
        m_count--;
        return el;
    }
}
// delete the first node in the list where the num matches
// 1 no element matches
// 2 first
// 3 last
// middle
template<typename T>
T DLinkedListADT<T>::deleteFirstInstance(const T &element){
    Node<T> *tmp = new Node<T>();
    tmp=head;
    if(head == NULL){
        cout<<"Empty list!"<<endl;
        return -1;
    }
    // find the element to delete
    for(int i=1; (i<=m_count)&&(tmp->info!=element); tmp=tmp->next, i++);
    if(tmp == NULL){
        cout<<endl;
        cout<<"no such element matches!"<<endl;
        return element;
    }
    else if(tmp == head){
        int re = deleteFirst();
        return re;
    }
    else if((tmp->next == NULL) && (tmp != NULL)){
        int re = deleteLast();
        return re;
    }
    else{
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
        m_count--;
        cout<<endl;
        return element;
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
