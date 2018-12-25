/*
 *programmed by Yiwen Zhao
 *quick sort
 */
#ifndef QUICK_SORT
#define QUICK_SORT

using namespace std;

template<typename T>
class QuickSort{
public:
    QuickSort(T *&ori_arr, int ori_num);
    void quickSort();
    void quickSort(T *&arr, int start_pos, int end_pos);
    void printData();
private:
    T *data;
    int m_n;
};
 //
template<typename T>
QuickSort<T>::QuickSort(T *&ori_arr, int ori_num){
    m_n = ori_num;
    data = ori_arr;
}
template<typename T>
void QuickSort<T>::quickSort(){
    quickSort(data, 0, (m_n - 1));
}
//
template<typename T>
void QuickSort<T>::quickSort(T *&arr, int start_pos, int end_pos){
    if(start_pos < end_pos){       // check if the sub array is only one element
        int base = arr[start_pos]; // backup the first element of the sub array
        int tmp1;                  // variant
        int left = start_pos;      // backup the start position   !!!!!!
        int right = end_pos;       // backup the end position     !!!!!!
        while(left < right){       // if left position number is less than right position number step into
            if(arr[right] >= base){      // if right sub array element greater than base element
                right--;                 // position moves to the left side
            }
            else if(arr[left] <= base){  // if left sub array element less than base element
                left++;                  // position moves to the right side
            }
            // change the corresponding elements
            else if((arr[right] < base) && (arr[left] > base)){
                int tmp2 = arr[right];
                arr[right] = arr[left];
                arr[left] = tmp2;
            }
        }
        // change the base element and the element(left position == right position)
        tmp1 = arr[start_pos];
        arr[start_pos] = arr[left];
        arr[left] = tmp1;
        quickSort(data, 0, (left - 1));               // recursion left side
        quickSort(data, (start_pos + 1), (end_pos));  // recursion right side
        }
        return;
}
//
template<typename T>
void QuickSort<T>::printData(){
    for(int i=0; i<m_n; i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
#endif // QUICK_SORT
