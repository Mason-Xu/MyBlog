typedef struct Node * PtrToNode;
struct Node{    // 队列中的结点
    ElementType Data;
    PtrToQNode Next;
};
typedef PtrToQNode Position;

typedef struct QNode * PtrToQNode;
struct QNode{
    Position Front, Rear;   // 队列的头尾指针
    int MaxSize;            // 队列的最大容量
};
typedef PtrToQNode Queue;

// 判断队列是否为空
bool IsEmpty(Queue Q)
{
    return(Q->Front == NULL);
}

// 删除队列头结点
ElementType DeleteQ(Queue Q)
{
    Position FrontCell;
    ElementType FrontElem;

    if(IsEmpty(Q)){
        printf("队列空!");
        return ERROR;
    }else{
        FrontCell = Q->Front;   
        if(Q->Front == Q->Rear){    // 若队列只有一个元素
            Q->Front = Q->Rear = NULL;  // 删除后队列置为空
        }else{
            Q->Front = Q->Front->Next;
        }
        FrontElem = FrontCell->Data;

        free(FrontCell);    // 释放被删除结点空间
        return FrontElem;
    }
}

// TODO: 应用实例:多项式加法运算