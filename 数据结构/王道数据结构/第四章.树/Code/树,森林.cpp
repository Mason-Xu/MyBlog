// 树的存储结构
// 双亲表示法
#define MAX_TREE_SIZE 100   // 树中最多的结点树
typedef struct{             // 树的结点定义
    ElemType data;          // 数据元素
    int parent;             // 双亲位置域
}PTNode;
typedef struct{                     // 树的类型定义
    PTNode nodes[MAX_TREE_SIZE];    // 双亲表示
    int n;                          // 结点数
}PTree;

// 孩子兄弟表示法(二叉树表示法)
typedef struct CSNode{
    ElemType data;                                  // 数据域
    struct CSNode, *firstchild, *nextsibling;       // 第一个孩子和右兄弟指针
}CSNode,*CSTree;