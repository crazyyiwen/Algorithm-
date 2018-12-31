#include <iostream>
#include "ajacentMatrix.h"

int main()
{
    AJAMatrix<int> *test = new AJAMatrix<int>;
    //test->inputData();
    test->test();
    test->printData();
    cout<<"-------------------------------"<<endl;
    test->depthIterator();
    return 0;
}
