
// 用邻接矩阵表示图 
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv; // 顶点数
    int Ne; // 边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum]; // 存顶点的数据
};
typedef PtrToGNode MGraph;  // 以邻接矩阵存储的图类型

// MGraph初始化
// 初始化一个有VertexNum个顶点但没有边的图
typedef int Vertex; // 用顶点下标表示顶点
MGraph CreateGraph(int VertexNum){
    Vertex V,W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    GNode->Ne = 0;

    // 注意: 这里默认顶点编号从0开始,从(Graph->Nv-1)
    for(V=0;V<Graph->Nv;V++){
        for(W=0;W<Graph->Nv;W++){
            Graph->G[V][W] = 0; // 或INFINITY 无穷大
        }
    }
    return Graph;
}

// 向MGraph中插入边
typedef struct ENode *PtoToENode;

struct ENode
{
    Vertex V1,V2;   // 有向边<V1,V2>
    WeightType Weight;  // 权重
};
typedef PtrToENode Edge;

void InsertEdge(MGraph Graph,Edge E){
    // 插入边 <V1,V2>
    Graph->G[E->V1][E->V2] = E->Weight;
    // 若是无向图,还要插入边<V2,V1>
    Graph->G[E->V2][E->V1] = E->Weight;
}

// 完整的建立一个MGraph
// 输入格式 Nv,Ne,  V1,V2 , Weight

MGraph BulidGraph(){
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph = CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }

    // 如果顶点有数据的话,读入数据
    for(V=0;V<Graph->Nv;V++){
        scanf("%c",&(Graph->Data[V]));
    }
    return Graph;
}


// 简单build
int G[MAXN][MAXN] , Nv,Ne;
void BulidGraph(){
    int i,j,v1,v2,w;
    scanf("%d",&Nv);
    // CreateGraph
    for(i = 0;i<Nv;i++){
        for(j=0;i<Nv;i++){
            G[i][j] = 0;    // 或者无限大
        }
    }
    scanf("%d",&Ne);
    for(i =0 ;i<Ne;i++){
        scanf("%d %d %d ",&v1,&v2,&w);
        // InsertEdge
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
}

