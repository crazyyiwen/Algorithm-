/**********************************************
 * Programmed by Yiwen Zhao
 * Course CS610
 * Student ID: 243358
 * File name: main.cpp
 * Abstract: Implement kinds of sort methods
 *
 *
 * Finished date: 12/10/2018
 *********************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include "Sort.h"


int main()
{
    // generate the random number
    //unsigned int datapass[20];
    //srand((unsigned)time(NULL));
    //for(int i=0; i<20; i++)
    //    datapass[i] = rand();
    //for(int i=0; i<20; i++)
    //    cout<<datapass[i]<<endl;
    //int n;
    //cout<<"please input the array size: ";
    //cin>>n;
    //cout<<endl;
    //SORT<int> A(n);
    //for(int i=0, len=A.length(); i<len; i++){
    //    cin>>n;
    //    A[i] = n;
    //}
    //cout<<endl;
    //for(int i=0, len=A.length(); i<len; i++){
    //    cout<<A[i]<<" "<<endl;
    //}
    unsigned int datapass[] = {2, 98, 3, 14, 5, 65, 1};
    unsigned int *p;
    p = datapass;
    SORT<unsigned int> *test = new SORT<unsigned int>();
    //test->insertionSort(p, sizeof(datapass)/sizeof(int));
    //test->selectionSort(p, sizeof(datapass)/sizeof(int));
    //test->bubbleSort(p, sizeof(datapass)/sizeof(int));
    DWORD start_time = GetTickCount();                   // start time
    test->mergeSort(p, sizeof(datapass)/sizeof(unsigned int));
    DWORD end_time = GetTickCount();                     // end time
    cout<<endl;
    cout<< "the sorted data : "<<endl;                   // consumption time
    test->printData(p, sizeof(datapass)/sizeof(unsigned int));
    cout<<endl;
    cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;
}
