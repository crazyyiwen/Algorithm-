#define MAXSIZE 100

using namespace std;

// edge node
typedef struct EdgeNode{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
// vertex node
typedef struct VertexNode{
    char data;
    EdgeNode *firstEdge;
}VErtexNode, AdjList[MAXVEX];
// graph list
typedef struct{
    AdjList adjList;
    int numVertexes, numEdges;
}GraphAdjList;

template<typename T>
class ADJGrapgh{
public:
    ADJGraph();
    void createGraphList();
private:
    GraphAdjList *m_GL;
    EdgeNode *m_EN;
};
//
template<typename T>
ADJGraph<T>::ADJGraph(){
    ;
}
//
template<typename T>
void ADJGraph<T>::createGraphLsit(){
    int i, j, k;
    cout<<"please input the number of vertexes and the number of edges"<<endl;
    cin>>m_GL->numVertexes;
    cin>>m_GL->numEdges;
    cout<<"-----------------------------------------------------------"<<endl;
    for(i=0; i<m_GL->numVertexes; i++){
        cin>>m_GL->adjList[i].data;
        m_GL->adjList[i].firstEdge = NULL;
    }
    // input Vj--Vk
    for(i=0; i<m_GL->numEdges; i++){
        cin>>j;
        cin>>k;
        m_EN = new EdgeNode；
        m_EN->adjvex = k;
        m_EN->next = m_GL->adjList[j].firstEdge;
        m_GL->adjList[j].firstEdge = m_EN;

        m_EN = new EdgeNode;
        m_En->adjvex = j;
        m_EN->next = m_GL->adjList[k].firstEdge;
        m_GL->adjList[k].firstEdge = m_EN;
    }
}
