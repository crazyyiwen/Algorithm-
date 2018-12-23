/**********************************************
 * Programmed by Yiwen Zhao
 * Course CS610
 * Student ID: 243358
 * File name: Sort.h
 * Abstract:  Implement data as raw array and
 *            implement merge sort (to sort in ascending order)
 *            that we discussed in class (recursive version)
 *            to sort the data.
 *
 *
 * Finished date: 12/10/2018
 *********************************************/
using namespace std;

template<typename T>
class SORT{
public:
    SORT(int length = 0);
    ~SORT();
    void insertionSort(T *&data, unsigned int len);
    void selectionSort(T *&data, unsigned int len);
    void bubbleSort(T *&data, unsigned int len);
    void mergeSort(T *&data1, unsigned int len);                          // takes the array of integer elements
                                                                          // and sorts it in increasing order
    void mergeSort(T *&data2, unsigned int firstN, unsigned int lastN);   // recursive function
    void mergeFun(T *&data3, unsigned int firstN, unsigned int lastN);    // merge two sub arrays in sorted order
    void printData(T *&data, unsigned int len);                           // print the data
    T &operator[](int i);
    int length()const{return m_length;};
private:
    T tmp[9];
    int m_length;
    T *m_p;
};
//
template<typename T>
SORT<T>::SORT(int length): m_length(length){
    for(int i=0; i<9; i++){
        tmp[i] = 0;
    }
    if(length == 0)
        m_p = NULL;
    else
        m_p = new unsigned int[length];
}
//
template<typename T>
SORT<T>::~SORT(){
    delete [] m_p;
}
//
template<typename T>
T &SORT<T>::operator[](int i){
    return m_p[i];
}
//
template<typename T>
void SORT<T>::insertionSort(T *&data, unsigned int len){
    if(len == 0)
        return;
    else{
        T tmp;
        for(unsigned int i=1, j; i<len; i++){
            tmp = data[i];
            for(j=i; j>0&&(tmp<data[j-1]);j--){
                data[j] = data[j-1];
            }
            data[j] = tmp;
        }
    }
}
//
template<typename T>
void SORT<T>::selectionSort(T *&data, unsigned int len){
    if(len == 0)
        return;
    else{
        T mid = 0;
        for(unsigned int i=0, j=0; i<len-1; i++){
            for(j=i+1; j<len; j++){
                if(data[i] <= data[j])
                    ;
                else{
                    mid = data[i];
                    data[i] = data[j];
                    data[j] = mid;
                }
            }
        }
    }
}
//
template<typename T>
void SORT<T>::bubbleSort(T *&data, unsigned int len){
    if(len == 0)
        return;
    else{
        T tmp = 0;
        for(unsigned int i=0, j=0; i<len-1; i++){
            for(j=len-1; j>i; j--){
                if(data[j] >= data[j-1])
                    ;
                else{
                    tmp = data[j];
                    data[j] = data[j-1];
                    data[j-1] = tmp;
                }
            }
        }
    }
}
// takes the array of integer elements and sorts it in increasing order
template<typename T>
void SORT<T>::mergeSort(T *&data1, unsigned int len){
    mergeSort(data1, 0, len-1);                              // step into the recursive function
}
// recursive function
template<typename T>
void SORT<T>::mergeSort(T *&data2, unsigned int firstN, unsigned int lastN){
    if(firstN < lastN){
        // separate the array into two left tree and right tree
        mergeSort(data2, firstN, (firstN + lastN)/2);        // recursive left tree
        mergeSort(data2, ((firstN + lastN)/2 + 1), lastN);   // recursive right tree
        mergeFun(data2, firstN, lastN);                      // sort each sub array
    }
}
// merges two sub arrays in sorted order
template<typename T>
void SORT<T>::mergeFun(T *&data3, unsigned int firstN, unsigned int lastN){
    unsigned int m_mid2 = (firstN + lastN)/2;                // get the middle index of the sub array as the left tree sub array last index
    unsigned int m_i2 = firstN;                              // get the first index of each sub array as the left tree sub array first index
    unsigned int m_i4 = firstN;                              // backup the firstN
    unsigned int m_i3 = m_mid2 + 1;                          // get the last index of each sub array as the right tree sub array last index
    // rearrange the left sub array and right sub array
    while((m_i2 <= m_mid2) && (m_i3 <= lastN)){
        if(data3[m_i2] < data3[m_i3])                        // right sub array element < left sub array element
            tmp[m_i4++] = data3[m_i2++];                     // copy the corresponding left sub array element to the tmp[]
        else
            tmp[m_i4++] = data3[m_i3++];                     // otherwise copy the corresponding right sub array element to the tmp[]
    }
    // copy the rest elements to tmp[]
    while(m_i2 <= m_mid2)
        tmp[m_i4++] = data3[m_i2++];
    while(m_i3 <= lastN)
        tmp[m_i4++] = data3[m_i3++];
    // refresh and update the data3[]
    for(unsigned int i=firstN; i<=lastN; i++){
        data3[i] = tmp[i];
    }
    // print the sorted sub array
    for(unsigned int i=firstN; i<=lastN; i++){
        cout<<tmp[i]<<" ";
    }
    cout<<endl;

}
// print the data
template<typename T>
void SORT<T>::printData(T *&data, unsigned int len){
    for(unsigned int i=0; i<len; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
//

