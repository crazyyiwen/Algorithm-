#include <iostream>
#include "BreadthFirstSearch.h"
#include "Queue.h"

int main(){
    AJAMatrix<int> *Test = new AJAMatrix<int>;
    Test->test();
    Test->printData();
    cout<<"---------------------------------"<<endl;
    Test->breadthIterator();

}
