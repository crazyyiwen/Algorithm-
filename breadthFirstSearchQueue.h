#include "Queue.h"
#ifndef AJAMATRIX
#define AJAMATRIX

#define DATASIZE 100
#define INFINITY 65535

template<typename T>
class AJAMatrix{
public:
    AJAMatrix();
    void inputData();
    void printData();
    void depthIterator();
    void depthIterator(int h);
    void breadthIterator();
    void breadthIterator(int h);
    void test();
private:
    int m_value;
    T m_vex[DATASIZE];
    bool tf_vex[DATASIZE];
    T m_data[DATASIZE][DATASIZE];
    int m_numVex, m_numEdge, m_i, m_j;
private:
    QCLASS<int> *qcl;
};
//
template<typename T>
AJAMatrix<T>::AJAMatrix(){
    qcl = new QCLASS<int>;
    m_value = 0;
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
//
template<typename T>
void AJAMatrix<T>::breadthIterator(){
    breadthIterator(0);
}
// m_numVex, m_numEdge tf_vex[DATASIZE] m_data[DATASIZE][DATASIZE]
template<typename T>
void AJAMatrix<T>::breadthIterator(int h){
        if(m_numVex == 0)
            return;
        for(int a=h; a<m_numVex; a++){
            for(int b=0; b<m_numVex; b++){
                if((a == 0) && (tf_vex[a] != true)){
                    tf_vex[a] = true;
                    qcl->insertQueue(a);
                    qcl->printQueue();
                    m_value = qcl->deleteQueue();
                    breadthIterator(m_value);
                }
                else if((m_data[a][b] == 1) && (tf_vex[b] != true)){
                    tf_vex[b] = true;
                    qcl->insertQueue(b);
                }
            }
            qcl->printQueue();
            m_value = qcl->deleteQueue();
            breadthIterator(m_value);
        }
}
//
template<typename T>
void AJAMatrix<T>::test(){
    m_numVex = 9;
    m_numEdge = 15;
    for(int i=0; i<m_numVex; i++)
        m_vex[i] = i;
    m_data[0][1] = m_data[1][0] = 1;
    m_data[0][5] = m_data[5][0] = 1;
    m_data[1][2] = m_data[2][1] = 1;
    m_data[1][6] = m_data[6][1] = 1;
    m_data[1][8] = m_data[8][1] = 1;
    m_data[2][3] = m_data[3][2] = 1;
    m_data[2][8] = m_data[8][2] = 1;
    m_data[3][4] = m_data[4][3] = 1;
    m_data[3][6] = m_data[6][3] = 1;
    m_data[3][7] = m_data[7][3] = 1;
    m_data[3][8] = m_data[8][3] = 1;
    m_data[4][5] = m_data[5][4] = 1;
    m_data[4][7] = m_data[7][4] = 1;
    m_data[5][6] = m_data[6][5] = 1;
    m_data[6][7] = m_data[7][6] = 1;
}

#endif // AJAMATRIX


/*
if(m_numVex == 0)
            return;

        for(int a=h; a<m_numVex; a++){
            for(int b=0; b<m_numVex; b++){
                if((a == 0) && (tf_vex[a] != true)){
                    break;
                }
                else if((m_data[a][b] == 1) && (tf_vex[b] != true)){
                    tf_vex[b] = true;
                    qcl->insertQueue(b);
                }
            }
            if((a == 0) && (tf_vex[a] != true)){
                tf_vex[a] = true;
                qcl->insertQueue(a);
                qcl->printQueue();
                m_value = qcl->deleteQueue();
                breadthIterator(m_value);
            }
            else{
                qcl->printQueue();
                m_value = qcl->deleteQueue();
                breadthIterator(m_value);
            }
        }
*/
