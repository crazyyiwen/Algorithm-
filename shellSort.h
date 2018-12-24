/*
 *programmed by Yiwen Zhao
 *Shellsort is a generalization of insertion sort
 *that allows the exchange of items that are far apart.
 *The idea is to arrange the list of elements so that,
 *starting anywhere, considering every hth element gives
 *a sorted list. Such a list is said to be h-sorted.
 *Equivalently, it can be thought of as h interleaved lists,
 *each individually sorted. Beginning with large values of h,
 *this rearrangement allows elements to move long distances
 *in the original list, reducing large amounts of disorder quickly,
 *and leaving less work for smaller h-sort steps to do.
 *If the list is then k-sorted for some smaller integer k,
 *then the list remains h-sorted. Following this idea for a
 *decreasing sequence of h values ending in 1 is guaranteed
 *to leave a sorted list in the end.
*/
#ifndef SHELL_SORT
#define SHELL_SORT

using namespace std;

template<typename T>
class shellSort{
public:
    shellSort();
    void shellSortImp(T *&data, unsigned int len);
    void printData(T *&data, unsigned int len);
private:
    unsigned int m_gap;
};
//
template<typename T>
shellSort<T>::shellSort(){
    m_gap = 0;
}
//
template<typename T>
void shellSort<T>::shellSortImp(T *&data, unsigned int len){
    unsigned int insertNum;
    m_gap = (len/2) +1;
    for(; m_gap>0; m_gap--)
        // from the m_gap position to the end, these steps
        // can iterate all the rest elements of the data
        for(unsigned int j=m_gap; j<len; j++){
            insertNum = data[j];
            unsigned int t = j;
            while((t >= m_gap) && (insertNum < data[t - m_gap])){
                data[t] = data[t - m_gap];
                t = t - m_gap;
            }
            data[t] = insertNum;
        }
}
//
template<typename T>
void shellSort<T>::printData(T *&data, unsigned int len){
    for(unsigned int i=0; i<len; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
#endif // SELL_SORT
