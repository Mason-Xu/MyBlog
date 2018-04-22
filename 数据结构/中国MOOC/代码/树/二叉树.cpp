// 链式存储
typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};

//  递归遍历
//  先序遍历
void PreOrderTraversal(BinTree BT){
    if(BT){
        printf("%d ",BT->Data); // 假设数据为整型
        PreOrderTraversal(BT->Left);
        // 此处假设对BT结点的访问就是打印数据
        PreOrderTraversal(BT->Right);
    }
}
//  中序遍历
void InOrderTraversal(BinTree BT){
    if(BT){
        InOrderTraversal(BT->Left);
        // 此处假设对BT结点的访问就是打印数据
        printf("%d ",BT->Data); // 假设数据为整型
        InOrderTraversal(BT->Right);
    }
}
//  后序遍历
void PostOrderTraversal(BinTree BT){
    if(BT){
        PostOrderTraversal(BT->Left);
        // 此处假设对BT结点的访问就是打印数据
        PostOrderTraversal(BT->Right);
        printf("%d ",BT->Data); // 假设数据为整型
    }
}

//  层次遍历
void LevelOrderTraversal(BinTree BT){
    Queue Q;
    BinTree T;

    if(!BT) return; // 若是空树则直接返回

    Q = CreatQueue();   // 创建空队列Q
    AddQ(Q,BT);

    while(!IsEmpty(Q)){
        T = DeleteQ(Q);
        printf("%d ",T->Data);  // 访问去除队列的结点
        if(T->Left) AddQ(Q,T->Left);
        if(T->Right) AddQ(Q,T->Right);
        
    } 
}


//  二叉树的非递归遍历  

// 中序遍历  
void InOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack s = CreatStack(MaxSize);  // 创建并初始化堆栈s
    while(T || !IsEmpty(S)){
        while(T){
            Push(S,T);
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S); // 结点弹出堆栈
            printf("%5d", T->Data); // 访问打印结点
            T = T->Right;   // 转向右子树 
        }
    }
}



// 遍历二叉树应用:输出二叉树中的叶子结点  利用先序遍历
void PreOrderPrintLeaves(BinTree BT){
    if(BT){
        if(!BT->Left && !BT->Right){
            prinf("%d",BT->Data);
        }
        PreOrderPrintLeaves(BT->Left);
        PreOrderPrintLeaves(BT->Right);
    }
}

// 求二叉树的高度

int PostOrderGetHight(BinTree BT){
    int HL,HR,MaxH;
    if(BT){
        HL = PostOrderGetHight(BT->Left);   // 求左子树的深度
        HR = PostOrderGetHight(BT->Right);  // 求右子树的深度
        MaxH = (HL > HR)? HL : HR;  // 取左右子树较大的深度
        return ( MaxH + 1 );    // 返回树的深度
    }else{
        return 0;   // 空树深度返回0
    }
}