/**********************************************
 * Programmed by Yiwen Zhao
 * Course CS610
 * Student ID: 243358
 * File name: BSTtest.cpp
 * Abstract: Implement Binary Search Tree ADT
 *           for the pseudo code
 * Finished date: 12/15/2018
 *********************************************/
#include <iostream>
#include "BST.h"

int main(){
    BSTThrTree midValue   = NULL;
    BST<int> *test = new BST<int>();
    test->createBSTThrTree();
    cout<<"after in order traverse iteration: "<<endl;
    test->traverseInOrder();
    cout<<endl;
    try{
        midValue = test->findNode(6);
        cout<<"the key is : "<<midValue->data<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    midValue = test->findMin();
    cout<<"the min value is : "<<midValue->data<<endl;
    midValue = test->findMax();
    cout<<"the max value is : "<<midValue->data<<endl;
    cout<<"please insert a key: ";
    test->insertNode(6);
    cout<<endl;
    cout<<"after insert the new tree is : ";
    test->traverseInOrder();
    cout<<endl;
    cout<<"after delete the new tree is : ";
    test->deleteNode(3);
    test->traverseInOrder();
    cout<<endl;
    cout<<"the sum nodes of the tree is : ";
    cout<<test->sumNodes()<<endl;
    cout<<endl;
    cout<<"the average values of the tree is : ";
    cout<<test->averageTree()<<endl;
    cout<<endl;
    return 0;
}
