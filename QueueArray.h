/*generic queue implemented as an array
 *circle queue
 *save space
 */
#ifndef QUEUE_ADT
#define QUEUE_ADT

using namespace std;
template<typename T>
class QueueADT{
public:
    QueueADT(int MAX);
    void enQueue(int element);
    T deQueue();
    int eleCount();
    bool isEmpty();
    bool isFull();
    void printQueue();
private:
    int m_first, m_last;
    T item[8];
    int m_eleCount;
    int m_size;
};
//constructor initialization
template<typename T>
QueueADT<T>::QueueADT(int MAX){
    for(int i=0; i<8; i++){
        item[i] = 0;         // all original 0 elements
    }
    m_first = m_last = -1;
    m_size = MAX;
    m_eleCount = 0;
}
template<typename T>
bool QueueADT<T>::isFull(){
    return ((m_first == 0 && m_last == m_size - 1) || (m_first == m_last + 1));
}
template<typename T>
bool QueueADT<T>::isEmpty(){
    return m_first == -1 && m_last == -1;
}
template<typename T>
int QueueADT<T>::eleCount(){
    return m_eleCount;
}
template<typename T>
void QueueADT<T>::enQueue(int element){
    if(!isFull()){
            /*
            if(m_first == m_last){
                m_first = m_last = 0;
                item[0] = element;
            }
            else if(m_last == m_size - 1){
                m_last = 0;
                item[0] = element;
            }
            else
                item[++m_last] = element;
            */
        // if not full add element at the beginning of the queue
        if(m_last == m_size - 1 || m_last == -1){
            item[0] = element;
            m_eleCount++;
            m_last = 0;
            if(m_first == -1)
                m_first = 0;
        }
        // else add the element to the next position
        else{
            item[++m_last] = element;
            m_eleCount++;
        }
    }
    else{
        // need add the throw part!!!
        cout<<"Full queue!"<<endl;
    }
}
template<typename T>
T QueueADT<T>::deQueue(){
    if(!isEmpty()){
        if(m_first == m_last){
            int el = item[m_first];
            m_eleCount--;
            item[m_first] = 0;
            m_first = m_last = -1;
            return el;
        }
        else if(m_first == m_size - 1){
            int el = item[m_first];
            m_eleCount--;
            item[m_first] = 0;
            m_first = 0;
            return el;
        }
        else{
            int el = item[m_first];
            m_eleCount--;
            item[m_first++] = 0;
            return el;
        }
    }
    else{
        cout<<"The queue is empty!\n"<<endl;
        return -2;
    }
}
// print the queue one by one
template<typename T>
void QueueADT<T>::printQueue(){
    cout<<"The Queue is: ";
    for(int i=0; i<8; i++){
        cout<<item[i]<<" ";
    }
    cout<<endl;
}
#endif // QUEUE_ADT
