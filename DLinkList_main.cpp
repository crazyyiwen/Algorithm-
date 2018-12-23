#include <iostream>
#include "DLinkedListADT.h"
#define arrSize 8
template<typename T>
class TestDeleteFirstInstance{
public:
    TestDeleteFirstInstance();
public:
    void printList();
    void deleF();
    void deleL();
    void deleE(const T &el);
private:
    int values;
    DLinkedListADT<T> *q;
};
//build linkedlist
template<typename T>
TestDeleteFirstInstance<T>::TestDeleteFirstInstance(){
    values = 0;
    // List initialization
    int arr[arrSize] = {12, 34, 65, 76, 23, 22, 36, 90};
    q = new DLinkedListADT<int>();
    for(unsigned int i=0; i<sizeof(arr)/sizeof(int); i++){
        q->addLast(arr[i]);
    }
}
//delete first
template<typename T>
void TestDeleteFirstInstance<T>::deleF(){
    values = q->deleteFirst();
    cout<<endl;
    cout<<"num "<<values<<endl;
    cout<<"modified list element: ";
    q->printNextList();
    cout<<endl;
}
//delete last
template<typename T>
void TestDeleteFirstInstance<T>::deleL(){
    values = q->deleteLast();
    cout<<endl;
    cout<<"num "<<values<<endl;
    cout<<"modified list element: ";
    q->printNextList();
    cout<<endl;
}
//delete anyone
template<typename T>
void TestDeleteFirstInstance<T>::deleE(const T &el){
    values = q->deleteFirstInstance(el);
    cout<<"num:"<<values<<endl;
    cout<<"modified list element: ";
    q->printNextList();
    cout<<endl;

}
//print list
template<typename T>
void TestDeleteFirstInstance<T>::printList(){
    q->printNextList();
    cout<<endl;
}
//main function
int main(){
    cout<<endl;
    //create test instance
    TestDeleteFirstInstance<int> *test = new TestDeleteFirstInstance<int>();
    cout<<"The original List is : ";
    test->printList();
    test->deleF();
    test->deleL();
    test->deleE(1);
    test->deleE(76);
    cout<<endl;
    //value = q->countSize();
    cout<<endl;
    return 0;
}
