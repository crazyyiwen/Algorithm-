/*
 *programmed by Yiwen Zhao
 *Maximum Heap by using array
 */
#ifndef HeapQueue
#define HeapQueue
using namespace std;

template<typename T>
class MaxHeap{
public:
    MaxHeap(T *heap, int num, int maxn);
    void buildHeap();
    int sizeHeap();
    bool isLeaf(int pos);
    int leftChild(int pos);
    int rightChild(int pos);
    int parentNode(int pos);
    void heapEnQueue(T el);
    T heapDlQueue(int pos);
    void printData();
private:
    void shiftDown(int pos);
    void swapData(T *heap, int node, int leaf);
private:
    T *m_heap;
    int m_maxsize;
    int m_n;
    int child_tmp1;
    int child_tmp2;
    int pn;
};
//
template<typename T>
MaxHeap<T>::MaxHeap(T *heap, int num, int maxn){
    m_heap = heap;
    m_n = num;
    m_maxsize = maxn;
    child_tmp1 = 0;
    child_tmp2 = 0;
    pn = 0;
    buildHeap();
}
//
template<typename T>
void MaxHeap<T>::buildHeap(){
    for(int i=(m_n/2 - 1); i>=0; i--)
        shiftDown(i);
}
//
template<typename T>
void MaxHeap<T>::shiftDown(int pos){
    while(!isLeaf(pos)){
        int L = leftChild(pos);
        int R = rightChild(pos);
        if((R < m_n) && m_heap[R] > m_heap[L])
            L = R;
        if(m_heap[pos] >= m_heap[L])
            return;
        swapData(m_heap, pos, L);
        pos = L;
    }
}
//
template<typename T>
bool MaxHeap<T>::isLeaf(int pos){
    return (pos >= m_n/2) && (pos < m_n);
}
//
template<typename T>
int MaxHeap<T>::leftChild(int pos){
    return 2*pos + 1;
}
//
template<typename T>
int MaxHeap<T>::rightChild(int pos){
    return 2*pos + 2;
}
//
template<typename T>
int MaxHeap<T>::parentNode(int pos){
    return (pos - 1)/2;
}
//
template<typename T>
void MaxHeap<T>::swapData(T *heap, int node, int leaf){
    child_tmp2 = heap[node];
    heap[node] = heap[leaf];
    heap[leaf] = child_tmp2;
}
//
template<typename T>
void MaxHeap<T>::heapEnQueue(T el){
    m_n = m_n + 1;
    m_heap[m_n - 1] = el;
    child_tmp1 = m_n - 1;
    pn = (m_n - 2)/2;
    while((pn >= 0) && (m_heap[child_tmp1] > m_heap[pn])){
        swapData(m_heap, pn, child_tmp1);
        child_tmp1 = pn;
        pn = parentNode(pn);
    }
}
//
template<typename T>
T MaxHeap<T>::heapDlQueue(int pos){
    if((pos >= 0)  && (pos < m_n))
        ;
    else
        return -1;
    if(pos == m_n - 1)
        m_n--;
    else{
        swapData(m_heap, pos, --m_n);
        while((pos != 0) && (m_heap[pos] > m_heap[parentNode(pos)])){
            swapData(m_heap, pos, parentNode(pos));
            pos = parentNode(pos);
        }
        if(m_n != 0)
            shiftDown(pos);
    }
    return m_heap[m_n];
}
template<typename T>
void MaxHeap<T>::printData(){
    for(int i=0; i<m_n; i++)
        cout<<m_heap[i]<<" ";
    cout<<endl;
}
//
#endif // HeapQueue
