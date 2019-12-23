//
//  main.cpp
//  C++DS5Graphlnk
//
//  Created by 赵桐 on 2019/11/27.
//  Copyright © 2019 赵桐. All rights reserved.
//
//#ifndef GRAPHLNK_H
//#define GRAPHLNK_H
//#include "Graphlnk.h"
#include "Graph.h"
#include "SeqQueue.h"
#include <cassert>
#include <iostream>
using namespace std;
const int DefaultVertices = 30;
//enum bool {false,true};


template<typename T, typename E>
struct Edge{
    int dest;
    E cost;
    Edge<T,E> *link;
    Edge(){}
    Edge(int num,E weight):dest(num),cost(weight),link(NULL){}
    bool operator !=(Edge<T,E>&R)const {return(dest!=R.dest)? true:false;}
    };


template<typename T, typename E>
struct  Vertex {
    T data;
    Edge<T,E> * adj;
};

//template<typename T, typename E>
//class Graph{
//protected:
//    int maxVertices;
//    int numEdges;
//    int numVertices;
//    virtual int getVertexPos(T vertex);
//public:
//    const E maxWeight =99999;
//    Graph(int sz = DefaultVertices)
//    {
//        maxVertices = sz;
//        numVertices = 0;
//        numEdges = 0;
//    }
//    Graph()
//    {
//        maxVertices = DefaultVertices;
//        numVertices = 0;
//        numEdges = 0;
//    }
//    ~Graph(){};
//    bool GraphEmpty()const{
//        if(numEdges ==0)return true;
//        else return false;
//    }
//    bool GraphFull()const{
//        if(numVertices==maxVertices||numEdges==maxVertices*(maxVertices-1)/2)return true;
//        else return false;
//    }
//    int NumberOfVertices(){return numVertices;}
//    int NumberOfEdges(){return numEdges;}
//    virtual T getValue(int i);
//    virtual E getWeight(int v1,int v2);
//    virtual int getFirstNeighbor(int v);
//    virtual int getNextNeighbor(int v,int w);
//    virtual bool insertVertex(const T&vertes);
//    virtual bool insertEdge(int v1,int v2,E cost);
//    virtual bool removeVertex(int v);
//    virtual bool removeEdge(int v1,int v2);
//};

//template<typename T, typename E>
//class Graphlnk :public Graph<T,E>{
template <typename T, typename E>class Graphlnk : public Graph<T,E>{
    Vertex<T,E> * NodeTable;

public:
    Graphlnk(int sz = DefaultVertices);
    ~Graphlnk();
    T getValue(int i){return (i>=0&&i<Graph<T,E>::NumberOfVertices())? NodeTable[i].data :0;}
    E getWeight(int v1, int v2);
    bool insertVertex(const T& vertex);
    bool removeVertex(int v);
    bool insertEdge(int v1,int v2,E cost);
    bool removeEdge(int v1,int v2);
    int getFirstNeighbor(int v);
    int getNextNeighbor(int v, int w);
    int getVertexPos(const T &vertex){
        for(int i=0;i<Graph<T,E>::numVertices;i++)
            if(NodeTable[i].data ==vertex)
                return i;
        return -1;

    }
    friend istream& operator >>(istream&in,Graphlnk <T,E>&G){
        //通过从输入流对象in输入n个顶点信息和e条边的信息建立用邻接表表示的图G。
        int numVer = 0,numEg = 0,j,k;
        T e1,e2;
        E weight;
        in >> numVer >> numEg;
        for(int i=0;i<numVer;i++)
        {
            in>>e1;
            G.insertVertex(e1);
        }
        for(int i=0;i<numEg;i++)
        {
            in>>e1>>e2>>weight;
            j = G.getVertexPos(e1);
            k = G.getVertexPos(e2);
            if(j==-1||k==-1)
            {
                cout<<"边两端点信息有误，重新输入！"<<endl;
                i--;
            }
            else{
            G.insertEdge(j, k, weight);
            }
        }
        return in;
    }
    
    void DFS(Graphlnk<T,E>&G,const T&v);
    void DFS(Graphlnk<T,E>&G,int v ,bool visited[]);
    void BFS(Graphlnk<T,E>&G,const T&v);
    void Components(Graphlnk<T,E>&G);
//    friend istream& operator >> (istream &in, Graphlnk<T,E> &G){
//        int i, j, k, n, m;
//        T e1, e2;
//        E weight;
//        in >> n >> m;                //输入顶点数与边数
//        for (i = 0; i < n; i++){    //依次输入顶点值
//            in >> e1;
//            G.insertVertex(e1);
//        }
//        i = 0;
//        while (i < m){
//            assert(in >> e1 >> e2 >> weight);    //依次输入边的两顶点值及其权值
//            j = G.getVertexPos(e1);                //取对应顶点下标
//            k = G.getVertexPos(e2);
//            if (j == -1 || k == -1){            //取对应顶点不存在
//                cout << "Input error!\n";
//            }
//            else{
//                G.insertEdge(j, k, weight);        //由顶点下标和权值插入边
//                i++;
//            }
//        }
//        return in;
//    }
//    friend ostream& operator <<(ostream&out,Graphlnk <T,E>&G);
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Graphlnk<char,int>  gl1;
    cin>>gl1;
//    gl1.BFS(gl1, 'A');
    gl1.Components(gl1);
    std::cout << "Hello, World!\n";
    return 0;
}
template<typename T, typename E>
Graphlnk<T, E>::Graphlnk(int sz):Graph<T, E>(sz)
{
    Graph<T,E>::maxVertices = sz;
    Graph<T,E>::numVertices = 0;
    Graph<T,E>::numEdges = 0;
    NodeTable = new Vertex<T, E>[Graph<T,E>::maxVertices];
    if(NodeTable==NULL){cerr<<"内存分配出错！"<<endl;exit(1);}
    for(int i=0;i<Graph<T,E>::maxVertices;i++)NodeTable[i].adj = NULL;
}
//析构函数：删除一个邻接表
template <typename T, typename E>Graphlnk<T,E>::~Graphlnk(){
    for (int i = 0; i < Graph<T,E>::numVertices; i++ ){        //删除各边链表中的结点
        Edge<T,E> *p = NodeTable[i].adj;         //找到其对应边链表的首结点
        while (p != NULL){                        //不断地删除第一个结点
            NodeTable[i].adj = p->link;
            delete p;
            p = NodeTable[i].adj;
        }
    }
    delete []NodeTable;              //删除顶点表数组
}
template<typename T, typename E>
int Graphlnk<T, E>::getFirstNeighbor(int v){
    //给出顶点位置为v的第一个邻接顶点的位置，如果找不到，则函数返回-1.
    if(v!=-1){
        Edge<T, E> * p  = NodeTable[v].adj;
        if(p!=NULL)return p->dest;
    }
    return -1;
}
template<typename T, typename E>
int Graphlnk<T, E>::getNextNeighbor(int v, int w){
    //给出顶点v的邻接定点w的下一个邻接顶点的位置，若没有下一个邻接顶点，则函数返回-1.
    if(v!=-1){
        Edge<T, E> *p = NodeTable[v].adj;
        while(p!=NULL &&p->dest!=w)
            p=p->link;
        if(p!=NULL&&p->link!=NULL)
            return p->link->dest;
    }
    return -1;
}
template<typename T, typename E>
E Graphlnk<T, E>::getWeight(int v1, int v2){
//template <typename T, typename E>E Graphlnk<T,E>::getWeight(int v1, int v2){
    //函数返回边（v1，v2）上的权值，若该边不在图中，则函数返回权值0.
    if(v1!=-1&&v2!=-1){
        Edge<T,E> *p = NodeTable[v1].adj;
        while (p!=NULL&&p->dest!=v2) {
            p=p->link;
        }
        if(p!=NULL)return p->cost;
    }
        return 0;
}
//template <typename T, typename E>E Graphlnk<T,E>::getWeight(int v1, int v2){
//    if (v1 != -1 && v2 != -1){
//        Edge<T,E> *p = NodeTable[v1].adj;            //V1的第一条关联的边
//        while (p != NULL && p->dest != v2){            //寻找邻接顶点v2
//            p = p->link;
//        }
//        if (p != NULL){
//            return p->cost;                //找到此边, 返回权值
//        }
//    }
//    return 0;                                        //边(v1,v2)不存在
//}
template<typename T, typename E>
bool Graphlnk<T, E>::insertVertex(const T&vertex){
    //在图的顶点表中插入一个新顶点vertex。若插入成功g，函数返回true，否则返回false。
    if(Graph<T,E>::numVertices==Graph<T,E>::maxVertices)return false;
    NodeTable[Graph<T,E>::numVertices].data = vertex;
    Graph<T,E>::numVertices++;
    return true;
}
template<typename T, typename E>
bool Graphlnk<T, E>::removeVertex(int v){
    //在图中删除一个指定顶点v，v是顶点号。若删除成功，函数返回true，否则返回false。
    if(Graph<T, E>::numVertices==1||v<=0||v>=Graph<T, E>::numVertices)return false;
    Edge<T, E>*p,*s,*t;
    int k;
    while (NodeTable[v].adj!=NULL){
        p = NodeTable[v].adj;k = p->dest;
        s = NodeTable[k].adj;t = NULL;
        while (s!=NULL&&s->dest!=v) {
            t = s;s = s->link;
        }
        if(s!=NULL){
            if(t==NULL)NodeTable[k].adj = s->link;
            else t->link = s->link;
            delete s;
        }
        NodeTable[v].adj = p->link;
        delete p;
        Graph<T, E>::numEdges--;
    }
    Graph<T, E>::numVertices--;
    NodeTable[v].data = NodeTable[Graph<T,E>::numVertices].data;
    p = NodeTable[v].adj = NodeTable[Graph<T,E>::numVertices].adj;
    while(p!=NULL){
        s= NodeTable[p->dest].adj;
        while (s!=NULL)
            if(s->dest==Graph<T,E>::numVertices){s->dest = v;break;}
            else s = s->link;
    }
    return true;
}
//上面代码有问题好像。在本子上写了一遍流程l，没有完全便利。
template<typename T, typename E>
bool Graphlnk<T, E>::insertEdge(int v1, int v2, E weight){
//在带权值图中插入一条边（v1,v2），若此边存在或者参数不合理，函数返回false，否则
//返回true。对于非带全图，最后一个参数weight不要，算法中相应语句也不要。
    if(v1>=0&&v1<Graph<T, E>::numVertices&&v2>=0&&v2<Graph<T, E>::numVertices){
        Edge<T, E> *q ,*p = NodeTable[v1].adj;
        while (p!=NULL&&p->dest!=v2)
        {
            p=p->link;
        }
        if(p!=NULL)return false;
        p = new Edge<T, E>;
        q = new Edge<T, E>;
        p->dest = v2;
        p->cost = weight;//如果是非带权图，这句删了
        p->link = NodeTable[v1].adj;
        NodeTable[v1].adj = p;
        q->dest = v1;
        q->cost = weight;//如果是非带权图，这句删了
        q->link = NodeTable[v2].adj;
        NodeTable[v2].adj = q;
        Graph<T, E>::numEdges++;
        return true;
    }
    return false;
}
template<typename T, typename E>
bool Graphlnk<T, E>::removeEdge(int v1, int v2){
    //在图中删除一条边（v1，v2）
    if(v1!=-1&&v2!=-1){
        Edge<T, E> *p = NodeTable[v1].adj,*q = NULL,*s = p;
        while(p!=NULL&&p->dest!=v2){
            q = p; p=p->link;
        }
        if(p!=NULL){
            if(p==s)NodeTable[v1].adj = p->link;
            else q->link = p->link;
            delete p;
        }
        else return false;
        p = NodeTable[v2].adj;
        q = NULL;
        s=p;
        while(p->dest!=v1){q=p;p=p->link;}
        if(p==s)NodeTable[v2].adj = p->link;
        else q->link = p->link;
        delete p;
        return true;
    }
    return false;
}
   template<typename T, typename E>
   void Graphlnk<T, E>::DFS(Graphlnk<T,E>&G,const T&v)
//从定点v除法，对图G进行深度优先遍历的主过程
{
    int loc,n=G.NumberOfVertices();                 //取图中定点数
    bool * visited = new bool[n];                   //创建辅助数组
    for(int i=0;i<n;i++)visited[i]=false;           //辅助数组visited初始化
    loc = G.getVertexPos(v);
    DFS(G,loc,visited);
    delete [] visited;
}
    template<typename T, typename E>
    void Graphlnk<T, E>::DFS(Graphlnk<T,E>&G,int v ,bool visited[])
//从顶点位置v除法，以深度优先的次序访问所有克读入的尚未访问过的顶点。
//算法用一个辅助数组visited，s对已经访问过的顶点做访问标记。
{
    cout<<G.getValue(v)<<" ";                         //访问顶点v
    visited[v] = true;                                //顶点v作访问标记
    int w = G.getFirstNeighbor(v);                    //找顶点v的第一个邻接顶点w
    while(w!=-1){                                     //如果邻接顶点w存在
        if(visited[w]==false)DFS(G, w, visited);      //如果w未访问过，递归访问顶点w
        w = G.getNextNeighbor(v, w);                  //取v排在w后的下一个邻接顶点
    }
}
    template<typename T, typename E>
    void Graphlnk<T, E>:: BFS(Graphlnk<T,E>&G,const T&v)
//从顶点v除法，以广度优先的次序横向搜索图，算法中使用了一个队列。
{
    int i,w,n=G.NumberOfVertices();
    bool * visited = new bool[n];
    for(i=0;i<n;i++)visited[i]=false;
    int loc = G.getVertexPos(v);
    cout<< G.getValue(loc)<<" ";
    visited[loc] = true;
    SeqQueue<int> Q;Q.EnQueue(loc);
    while(!Q.IsEmpty()){
        Q.DeQueue(loc);
        w = G.getFirstNeighbor(loc);
        while(w!=-1){
            if(visited[w]==false){
                cout <<G.getValue(w)<<" ";
                visited[w] = true;
                Q.EnQueue(w);
            }
            w = G.getNextNeighbor(loc, w);
        }
    }
    delete [] visited;
}
template<typename T, typename E>
void Graphlnk<T, E>::Components(Graphlnk<T,E>&G){
    //通过DFS，找到无向图的所有连通分量
    int i,n=G.NumberOfVertices();//取图中顶点个数
    bool * visited = new bool[n];
    for(i=0;i<n;i++)visited[i] = false;
    for(i = 0;i<n;i++){
        if(visited[i]==false){
        DFS(G, i, visited);
//        cout <<G.getValue(i);
        }
    }
    delete [] visited;
    
}
