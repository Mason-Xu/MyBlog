typedef struct TNode *Position;
typedef Position BinTree;   // 二叉树类型
struct TNode{   // 树节点定义
    ElementType Data;   //  节点数据
    BinTree Left;   //指向左子树
    BinTree Right;  //指向右子树
};