#ifndef BREADTH_FIRST_SEARCH
#define BREADTH_FIRST_SEARCH

using namespace std;

typedef int ElementType;

typedef struct QNode{
    ElementType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr frontN, rearN;
}LinkQueue;

template<typename T>
class QCLASS{
public:
    QCLASS();
    void insertQueue(ElementType el);
    T deleteQueue();
    void printQueue();
private:
    T m_return;
    LinkQueue *m_queue;
};
//
template<typename T>
QCLASS<T>::QCLASS(){
    m_return = 0;
    m_queue = new LinkQueue;
    //??? and frontN and rearN point to the header node
    m_queue->frontN = m_queue->rearN = new QNode;
    if(!m_queue->frontN)
        exit(0);
    m_queue->frontN->next = NULL;
}
template<typename T>
void QCLASS<T>::insertQueue(ElementType el){
    QueuePtr p = new QNode;
    if(!m_queue->frontN)
        exit(0);
    p->data = el;
    p->next = NULL;
    m_queue->rearN->next = p;
    m_queue->rearN = p;
}
template<typename T>
T QCLASS<T>::deleteQueue(){
    QueuePtr q = new QNode;
    if(m_queue->frontN == m_queue->rearN)
        cout<<"queue is empty!!!"<<endl;
    q = m_queue->frontN->next;
    m_return = q->data;
    m_queue->frontN->next = q->next;
    if(m_queue->rearN == q)
        m_queue->rearN = m_queue->frontN;
    delete q;       // the deleted node must be deleted

    return m_return;
}
//
template<typename T>
void QCLASS<T>::printQueue(){
    QueuePtr q = m_queue->frontN->next;
    for(;q!=NULL;q=q->next)
        cout<<q->data<<" ";
    cout<<endl;
}
#endif // BREADTH_FIRST_SEARCH
