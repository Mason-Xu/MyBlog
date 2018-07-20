// 二叉树链式存储
typdef struct BiTNode{
    ElemType data;                              //数据域
    struct BiTNode *lchild,*rchild;             // 左右孩子指针
}BiTNode , *BiTree;

// 二叉树的遍历

// 先序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}

// 后序遍历
void PostOrder(BiTree T){
    if(T!=NULL){
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}

// 中序遍历非递归
void InOrder2(BiTree T){
    // 二叉树中序遍历的非递归算法.算法 需要一个 栈 stack
    InitStack(S),BiTree p = T;        // 初始化栈.p是遍历指针
    while(p || !IsEmpty(S)){          // 栈不空或p不空时循环
        if(p){                        // 栈指针进栈,遍历左子树
            Push(S,p);                // 每遇到非空二叉树先向左走
            p = p->lchild;
        }else{
            Pop(S,p);                 // 根指针退栈.访问根结点,遍历右子树
            visit(p);   
            p = p->rchild;            // 再向右子树走
        }
    }
}

// 层次遍历
void LevelOrder(BiTree T){
    // 层次遍历需要使用到队列
    InitQueue(Q);                     // 初始化队列 
    BiTree p;                       
    EnQueue(Q,T);                     // 根结点入队
    while(!IsEmpty(Q)){               // 队列不空时循环
        DeQueue(Q,p);                 // 队头退队,并返回给p指针
        visit(p);                     // 访问p当前指向的结点
        if(p->lchild != NULL){
            EnQueue(Q,p->lchild);     // 左子树不空,则左子树入队列
        }
        if(p->rchild != NULL){
            EnQueue(Q,p->rchild);     // 右子树不空,则右子树入队列
        }
    }
}