#include <iostream>
#include "StackADT.h"
#define typedef_ int

template<typename T>
class StackADT{
public:
    int m_num;
    StackADT(int max_num);
    bool isEmpty_F();
    bool isFull_F();
    void push(int item);
    T pop();
    int size_F();
    void print_F();
private:
    int m_capacity;
    DLinkedListADT<T> *q;
};
//
template<typename T>
StackADT<T>::StackADT(int max_num){
    m_num = 0;
    m_capacity = max_num;
    q = new DLinkedListADT<T>();
}
//
template<typename T>
bool StackADT<T>::isEmpty_F(){
    return m_num == 0;
}
//
template<typename T>
bool StackADT<T>::isFull_F(){
    return m_num == m_capacity;
}
//
template<typename T>
int StackADT<T>::size_F(){
    return m_num;
}
//
template<typename T>
void StackADT<T>::push(int el){
    if(m_num < m_capacity){
        q->addFirst(el);
        m_num++;
    }
    else
        cout<<"Error: stack is full!"<<endl;
}
//
template<typename T>
T StackADT<T>::pop(){
    T value;
    if((m_num > 0) && (m_num <= m_capacity)){
        value = q->deleteFirst();
        m_num--;
        return value;
    }
    else{
        cout<<"Error: stack is empty!"<<endl;
        return -1;
    }
}
//
template<typename T>
void StackADT<T>::print_F(){
    q->printNextList();
    cout<<endl;
}
//
int main()
{
    int mid;
    typedef_ arr[8]{2, 4, 6, 8, 10, 12, 14, 16};
    StackADT<int> *sq = new StackADT<int>(sizeof(arr)/sizeof(typedef_));
    sq->push(arr[0]);
    sq->push(arr[1]);
    sq->push(arr[2]);
    sq->print_F();
    mid = sq->pop();
    sq->print_F();
    cout<<"delete element is: "<<mid<<endl;
    cout<<"size "<<sq->m_num<<endl;
    return 0;
}
