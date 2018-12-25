#include <iostream>
#include "QuickSort.h"

int main()
{
    int data[] = {34,65,12,43,67,5,78,10,3,70};
    int *p;
    p = data;  //???
    QuickSort<int> *test = new QuickSort<int>(p, sizeof(data)/sizeof(int));
    test->quickSort();
    cout<<"after quick sort :";
    test->printData();
    return 0;
}
