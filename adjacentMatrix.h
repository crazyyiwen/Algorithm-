#ifndef AJACENT_MATRIX
#define AJACENT_MATRIX

#define DATASIZE 100
#define INFINITY 65535

using namespace std;

template<typename T>
class AJAMatrix{
public:
    AJAMatrix();
    void inputData();
    void printData();
    void depthIterator();
    void depthIterator(int h);
    void test();
private:
    T m_vex[DATASIZE];
    bool tf_vex[DATASIZE];
    T m_data[DATASIZE][DATASIZE];
    int m_numVex, m_i, m_j;
    int m_numEdge;
};
//
template<typename T>
AJAMatrix<T>::AJAMatrix(){
    m_i = m_numVex = 0;
    m_j = m_numEdge = 0;
    for(int i=0; i<DATASIZE; i++)
        m_vex[i] = INFINITY;
    for(int i=0; i<DATASIZE; i++)
        tf_vex[i] = false;
    for(int i=0; i<DATASIZE; i++)
        for(int j=0; j<DATASIZE; j++)
            m_data[i][j] = 0;
}
//
template<typename T>
void AJAMatrix<T>::inputData(){
    cout<<"please input the vertex: "<<endl;
    int el, head, tail;
    cin>>el;
    for(int i=0; (i<DATASIZE)&&(el!=-1); i++){
        m_vex[i] = el;
        m_numVex++;
        cin>>el;
    }
    cout<<"-------------------------------"<<endl;
    cout<<"please input the head-tail: ";
    cin>>head;
    cin>>tail;
    for(; head!=-1;){
        for(; tail!=-1;){
            m_data[head][tail] = m_data[tail][head] = 1;
            m_numEdge++;
            cout<<"please input the head-tail: ";
            cin>>head;
            cin>>tail;
        }
    }
}
//
template<typename T>
void AJAMatrix<T>::printData(){
    cout<<"-------------------------------"<<endl;
    cout<<"Vertex number is : "<<m_numVex<<endl;
    cout<<"Edge number is :"<<m_numEdge<<endl;
    cout<<"The adjacent matrix is :"<<endl;
    for(int i=0; i<m_numVex; i++){
        for(int j=0; j<m_numVex; j++)
            cout<<m_data[i][j]<<"  ";
        cout<<endl;
    }

}
//
template<typename T>
void AJAMatrix<T>::depthIterator(){
    depthIterator(0);
}
//
template<typename T>
void AJAMatrix<T>::depthIterator(int h){
    for(int i=h; i<m_numVex; i++){
        for(int j=0; j<m_numVex; j++){
            if((i==0)&&(j==0)){
                cout<<"V"<<j<<" ";
                tf_vex[j] = true;
            }
            else if((m_data[i][j] == 1) && (tf_vex[j] != true)){
                tf_vex[j] = true;
                cout<<"V"<<j<<" ";
                depthIterator(j);
            }
        }
        return;
    }
}
template<typename T>
void AJAMatrix<T>::test(){
    m_numVex = 8;
    m_numEdge = 9;
    for(int i=0; i<m_numVex; i++)
        m_vex[i] = i;
    m_data[0][1] = m_data[1][0] = 1;
    m_data[0][2] = m_data[2][0] = 1;
    m_data[0][3] = m_data[3][0] = 1;
    m_data[1][4] = m_data[4][1] = 1;
    m_data[2][3] = m_data[3][2] = 1;
    m_data[2][4] = m_data[4][2] = 1;
    m_data[3][5] = m_data[5][3] = 1;
    m_data[4][7] = m_data[7][4] = 1;
    m_data[5][6] = m_data[6][5] = 1;
}
#endif // AJACENT_MATRIX
