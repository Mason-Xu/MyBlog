// LGraph
// 邻接表: G[N]为指针数组,对应矩阵每行一个链表,只存非0元素
typedef struct GNode *PtrToGNode;

struct GNode
{
    int Nv; // 顶点数
    int Ne; // 边数
    AdjList G;  // 邻接表
};
typedef PtrToGNode LGraph;

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
    DataType Data;  // 存顶点的数据
}AdjList[MaxVertexNum];// AdjList 是邻接表类型

typedef PtrToGNode LGraph;
// 以邻接表方式存储的图类型

typedef struct AdjList *PtrToAdjVNode;

struct AdjVNode
{
    Vertex Adjv;    // 邻接点下标
    WeightType Weight;  // 边权重
    PteToAdjVNode NExt;
};

// 初始化一个有VertexNum顶点但没有边 的图
typedef int Vertex;     // 用顶点下标表示顶点,为整型
LGraph CreateGraph(int VertexNum){
    Vertex V,W;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;


    // 注意,这里默认顶点编号从0开始,到(Graph->Nv-1)
    for(V=0;V<Graph->Nv;V++){
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph;
}

// 向LGraph插入边
void InsertEdge(LGraph Graph,Edge E){
    PtrToAdjVNode NewNode;
    /*************插入<v1,v2>*************/
    // 为V2建立新的邻接点
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->Adjv = E->V2;
    NewNode->Weight = E->Weight;
    // 将V2插入V1的表头
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    /****若是无向图***插入<v2,v1>**********/
    // 为V1建立新的邻接点
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->Adjv = E->V1;
    NewNode->Weight = E->Weight;
    // 将V1插入V2表头
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

// 完整建立一个LGraph  与 建立 MGraph无区别