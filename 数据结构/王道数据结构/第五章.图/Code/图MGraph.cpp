// 图的邻接矩阵存储结构定义
#define MaxVertexNum 100    // 顶点数目的最大值    
typedef char VertexType;    // 顶点数据类型
typedef int EdgeType;       // 带权图中边上权值的数据类型
typedef struct{
    VertexType Vex[MaxVertexNum];   // 顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 邻接矩阵,边表
    int vexnum,arcnum;      // 图的当前定点数和弧数
}MGraph;

// 图的邻接表存储结构定义
#define MaxVertexNum 100    // 图中顶点数目的最大值
typedef struct ArcNode{     // 边结点
    int adjvex;             // 边表结点
    struct ArcNode *next;   // 指向下一条弧的指针
    // InfoType info;       // 网的边权值
}ArcNode;
typedef struct VNode{       // 顶点表结点
    VertexType data;        // 顶点信息
    ArcNode *first;         // 指向第一条依附该顶点的弧的指针
}VNode , AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;       // 邻接表
    int vernum , arcnum;    // 图的顶点数和弧数
}ALGraph;                   // ALGraph 是以邻接表存储的图类型


// 图的十字链表存储结构定义
#define MaxVertexNum 100    // 图中顶点数
typedef struct ArcNode{     // 边表结点
    int tailver , headvex;  // 该弧的头尾结点
    struct ArcNode *hlink, *tlink;  // 分别指向弧头相同的结点
    // InfoType info;       // 相关信息指针
}ArcNode;
typedef struct VNode{       // 顶点表结点
    VertexType data;        // 顶点信息
    ArcNode *firstin, *firstout;         // 指向第一条入弧和出弧
}VNode;
typedef struct{
    VNode xlist[MaxVertexNum];      // 邻接表
    int vernum , arcnum;    // 图的顶点数和弧数
}OLGraph;                   // OLGraph 是以十字邻接表存储的图类型

// 图的邻接多重表存储结构定义
#define MaxVertexNum 100    // 图中顶点数
typedef struct ArcNode{     // 边表结点
    bool mark;              // 访问标记
    int ivex , jvex;        // 分别指向该弧的两个结点
    struct ArcNode *ilink, *jlink;  // 分别指向两个顶点的下一条边
    // InfoType info;       // 相关信息指针
}ArcNode;
typedef struct VNode{       // 顶点表结点
    VertexType data;        // 顶点信息
    ArcNode *fristedge;     // 指向第一条媳妇该顶点的边
}VNode;
typedef struct{
    VNode adjmulist[MaxVertexNum];      // 邻接表
    int vernum , arcnum;    // 图的顶点数和弧数
}AMLGraph;                   // OLGraph 是以十字邻接表存储的图类型
