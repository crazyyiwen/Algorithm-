#include <iostream>
#include "QueueReverseMiddle.h"
//#include "StackADT.h"

template<typename L, typename T>
class QueueReverseMiddle{
public:
    QueueReverseMiddle();
    void queueReverseMiddle(L &que, T low, T high);
private:
    T m_num;
};

template<typename L, typename T>
QueueReverseMiddle<L, T>::QueueReverseMiddle(){
    m_num = 0;
}

// low:[1,4] high[5,8]
template<typename L, typename T>
void QueueReverseMiddle<L, T>::queueReverseMiddle(L &que, T low, T high){
    if(low <= 0 || high >= 9 || low >= high){
        throw 1;
    }
    else if(que.m_eleCount == 0){
        throw 1.0;

    }
    // EX: [1, 4]--1 and 4, 2 and 3/ EX: [1, 5]--1 and 5, 2 and 4, 3 not change
    else{
        cout<<"low: "<<low<<" high: "<<high<<endl;
        int h_l = ((high - low + 1) / 2);
        for(; h_l>0; h_l--){
            m_num = que.item[low-1];
            que.item[low-1] = que.item[high-1];
            que.item[high-1] = m_num;
            low++;
            high--;
        }
    }
}

int main()
{
    int arr[8] {2, 4, 6, 8, 12, 56, 37, 9};
    // QueueADT<int> q= new QueueADT<int>(8); error
    QueueADT<int> q(8);
    QueueReverseMiddle<QueueADT<int>, int> *r = new QueueReverseMiddle<QueueADT<int>, int>();
    for(int i=0; i<8; i++){
        q.enQueue(arr[i]);
    }
    cout<<"the original queue elements: ";
    q.printQueue();
    cout<<endl;
    try{
        r->queueReverseMiddle(q, 0, 6);
        cout<<"new queue elements : ";
        q.printQueue();
        cout<<endl;
    }
    catch(const int){
        cout<<"Error: out of scope!"<<endl;
    }
    catch(const float){
        cout<<"Error: empty array!"<<endl;
    }
    return 0;
}
