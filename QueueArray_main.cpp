#include <iostream>
#include "QueueArray.h"
#define CAPACITY 8

template<typename T>
class TestQueue{
public:
    TestQueue();
    void addElem(T el);
    T deleElem();
    int countElem();
    void printQ();
private:
    QueueADT<int> *que;
};
template<typename T>
TestQueue<T>::TestQueue(){
    que = new QueueADT<int>(CAPACITY);
}

template<typename T>
void TestQueue<T>::addElem(T el){
    que->enQueue(el);
}

template<typename T>
T TestQueue<T>::deleElem(){
    que->deQueue();
}

template<typename T>
int TestQueue<T>::countElem(){
    return que->m_eleCount;
}

template<typename T>
void TestQueue<T>::printQ(){
    que->printQueue();
}
int main()
{
    int arr[8] {2, 4, 6, 8, 12, 56, 37, 9};
    TestQueue<int> *q = new TestQueue<int>();
    q->addElem(arr[0]);
    q->addElem(arr[1]);
    q->addElem(arr[2]);
    q->addElem(arr[3]);
    q->addElem(arr[3]);
    q->addElem(arr[3]);
    q->addElem(arr[3]);
    q->addElem(arr[3]);
    //q->addElem(arr[3]);
    q->deleElem();
    q->addElem(arr[4]);
    q->printQ();
    cout<<endl;
    return 0;
}
