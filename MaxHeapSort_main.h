#include <iostream>
#include "HeapQueue.h"

int main()
{
    int value;
    int p[20] = {2, 8, 6, 1, 10, 15, 3, 12, 11};
    MaxHeap<int> *test = new MaxHeap<int>(p, 9, 20);
    test->heapEnQueue(20);
    test->heapEnQueue(32);
    value = test->heapDlQueue(0);
    cout<<"the delete value is :"<<value<<endl;
    test->heapSort();
    cout<<"after heap sort : ";
    test->printData();
    cout<<endl;
    return 0;
}
