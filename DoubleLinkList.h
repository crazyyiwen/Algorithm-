/**********************************************
 * Programmed by Yiwen Zhao
 * Course CS610
 * Student ID: 243358
 * File name: BST.h
 * Abstract: Implement Binary Search Tree ADT
 *           for the pseudo code
 * Finished date: 12/15/2018
 *********************************************/
#ifndef _BST_HEADER
#define _BST_HEADER


#define PrintSymbol %d
/*********************************************/
using namespace std;
typedef int ElemType;
typedef enum{Link, Thread} PointerTag;

typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lchild, *rchild;
    PointerTag ltag;
    PointerTag rtag;
}BSTThrNode, *BSTThrTree;
/*********************************************/
BSTThrTree preNode = NULL;
/*********************************************/
template<typename T>
class BST{
public:
    BST();
    ~BST();
    BSTThrTree findNode(T key);                        // find the key
    BSTThrTree findNode(BSTThrTree root, T key);       // associate function
    BSTThrTree findMin();                              // find smallest node recursively
    BSTThrTree findMin(BSTThrTree root);               // recursive part of findMin
    BSTThrTree findMax();                              // find largest node recursively
    BSTThrTree findMax(BSTThrTree root);               // recursive part of findMax

    void createBSTThrTree();                           // no arguments function
    void createBSTThrTree(BSTThrTree *node);           // create binary tree using pre-order traverse
    void InorderThreading(BSTThrTree headNode);        // iterate the binary tree
    void InThreading(BSTThrTree node);                 // associate fun for InorderThreading

    void insertNode(T data);                           // insert node in the tree using recursion
                                                       // it needs to find the correct place to keep binary search tree
    void insertInTree(BSTThrTree &root, T key);        // recursive part of insert
    void deleteNode(T data);                           // delete node on tree using recursion
    void deleteInTree(BSTThrTree &root, T key);        // recursive part of delete
    T minValue(BSTThrTree root);                       // get smallest value of the tree
    void traverseInOrder();                            // traverse node's in in-order and print key values
    void traverseInOrder(BSTThrTree root);             // recursive part of in-order
    void visit(BSTThrTree node);                       // print the data
    T sumNodes();                                      // calculate the sum value of the tree
    T sumNodes(BSTThrTree node);                       // recursive part of the sumNodes
    float averageTree();                               // calculate the average value of the tree
    BSTThrTree getRoot();
private:
    BSTThrTree normalNode;
    T m_sum;
    int m_count;
};
// constructor
template<typename T>
BST<T>::BST(){
    normalNode = NULL;
    m_sum = 0;
    m_count = 0;
}
//destructor
//preorder iterate threading
template<typename T>
void BST<T>::createBSTThrTree(){
    createBSTThrTree(&normalNode);
}
// create a binary search tree through the input data
template<typename T>
void BST<T>::createBSTThrTree(BSTThrTree *node){
    T el;
    cout<<"please input the node data: ";
    cin>>el;
    cin.clear();
    if(10 == el){
        *node == NULL;
    }
    else{
        *node = new BSTNode{};
        if(!*node){
            exit(1);
        }
        //
        (*node)->data = el;
        (*node)->ltag = Link;
        (*node)->rtag = Link;
        createBSTThrTree(&(*node)->lchild);
        createBSTThrTree(&(*node)->rchild);
    }
}
//head pointer point to the head root
template<typename T>
void BST<T>::InorderThreading(BSTThrTree headNode){
    headNode = new BSTNode{};
    (headNode)->ltag = Link;
    (headNode)->rtag = Thread;
    (headNode)->rchild = headNode;
    if(!normalNode){
        (headNode)->lchild = headNode;
    }
    else{
        (headNode)->lchild = normalNode;
        preNode = headNode;
        InThreading(normalNode);       //head root in
        preNode->rchild = headNode;
        preNode->rtag = Thread;
        (headNode)->rchild = preNode;
    }
}
//
template<typename T>
void BST<T>::InThreading(BSTThrTree node){
    if(node){
        InThreading(node->lchild);
        if(!node->lchild){
            node->ltag = Thread;
            node->lchild = preNode;      // first time bind the head pointer
        }
        visit(node);
        if(!preNode->rchild){
            preNode->rtag = Thread;
            preNode->rchild = node;
        }
        preNode = node;
        InThreading(node->rchild);
    }
}
// traverse node's in in-order and print key values
template<typename T>
void BST<T>::traverseInOrder(){
    traverseInOrder(normalNode);
}
// recursive part of in-order
template<typename T>
void BST<T>::traverseInOrder(BSTThrTree root){
    if(root != NULL){
        traverseInOrder(root->lchild);
        visit(root);
        traverseInOrder(root->rchild);
    }
}
// print the binary tree
template<typename T>
void BST<T>::visit(BSTThrTree node){
    cout<<node->data<<" ";
}
// find and return node in the tree with
// the key value using recursion
template<typename T>
BSTThrTree BST<T>::findNode(T key){
    return findNode(normalNode, key);
}
// recursive part of find
template<typename T>
BSTThrTree BST<T>::findNode(BSTThrTree root, T key){
    if(root == NULL)
        throw "the key is not in the tree or the tree is empty";
    else if(key < root->data)
        return findNode(root->lchild, key);
    else if(key > root->data)
        return findNode(root->rchild, key);
    else
        return root;
}
// find smallest node recursively(left most leaf node)
template<typename T>
BSTThrTree BST<T>::findMin(){
    return findMin(normalNode);
}
// recursive part of findMin
template<typename T>
BSTThrTree BST<T>::findMin(BSTThrTree root){
    if(root->lchild == NULL)
        return root;
    else
        return findMin(root->lchild);
}
// find largest node recursively(right most leaf node)
template<typename T>
BSTThrTree BST<T>::findMax(){
    return findMax(normalNode);
}
// recursive part of findMax
template<typename T>
BSTThrTree BST<T>::findMax(BSTThrTree root){
    if(root->rchild == NULL)
        return root;
    else
        return findMax(root->rchild);
}
// insert node in tree using recursion
// it needs to find the correct place to keep binary search tree
template<typename T>
void BST<T>::insertNode(T data){
    m_count++;
    insertInTree(normalNode, data);
}
// recursive part of insert
template<typename T>
void BST<T>::insertInTree(BSTThrTree &root, T key){
    if(root == NULL){
            root = new BSTNode{};
            root->data = key;
    }
    else if(key < root->data)
        insertInTree(root->lchild, key);
    else if(key > root->data)
        insertInTree(root->rchild, key);
    else
        ;
}
// delete node in tree using recursion
template<typename T>
void BST<T>::deleteNode(T data){
    m_count--;
    deleteInTree(normalNode, data);
}
// recursive part of delete
// 1 no child  2 one child 3 two children
template<typename T>
void BST<T>::deleteInTree(BSTThrTree &root, T key){
    if(NULL == root){
        return;
    }
    else{
        if(key < root->data){
            deleteInTree(root->lchild, key);
        }
        else if(key > root->data){
            deleteInTree(root->rchild, key);
        }
        else if(NULL != root->rchild && NULL != root->lchild){
            root->data = minValue(root->rchild);
            deleteInTree(root->rchild, root->data);
        }
        else{
            BSTThrTree oldNode = root;
            root = (NULL != root->lchild)?root->lchild:root->rchild;
            delete oldNode;
        }
    }
}
// get smallest value of the tree (left most leaf node)
template<typename T>
T BST<T>::minValue(BSTThrTree root){
    if(NULL != root){
        while(NULL != root->lchild){
            root = root->lchild;
        }
    }
    return root->data;
}
// get the sum values of the tree
template<typename T>
T BST<T>::sumNodes(){
    return sumNodes(normalNode);
}
// recursion part of the sumNodes
template<typename T>
T BST<T>::sumNodes(BSTThrTree root){
    if(root != NULL){
        sumNodes(root->lchild);
        m_sum += root->data;
        m_count++;
        sumNodes(root->rchild);
    }
    return m_sum;
}
// get the average value of the tree
template<typename T>
float BST<T>::averageTree(){
    int mid = 0;
    m_sum = 0;
    m_count = 0;
    mid = sumNodes();
    return (float)mid/(float)m_count;
}
#endif // _BST_HEADER

