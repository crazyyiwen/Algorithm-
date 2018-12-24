#include <iostream>
#include "ShellSort.h"

using namespace std;

int main()
{
    unsigned int data[] = {2, 8, 3, 3, 8, 6, 9};
    unsigned int *p;
    p = data;
    shellSort<unsigned int> *test = new shellSort<unsigned int>;
    test->shellSortImp(p, sizeof(data)/sizeof(unsigned int));
    test->printData(p, sizeof(data)/sizeof(unsigned int));
}
