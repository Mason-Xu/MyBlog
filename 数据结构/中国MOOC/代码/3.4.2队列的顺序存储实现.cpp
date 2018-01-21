typedef int Position;
typedef struct QNode * PtrToQNode;
struct QNode{
    ElementType * Data; // 存储元素的数组
    Position Front, Rear;   // 队列的头,尾指针
    int MaxSize;    // 队列最大容量
};
typedef PtrToQNode Queue;

// 生成空队列,最大长度为MaxSize
Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));   
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

// 判断队列是否已满
bool IsFull(Queue Q)
{
    return((Q->Rear+1) % Q->MaxSize == Q->Front);
}

// 判断队列是否为空
bool IsEmpty(Queue Q)
{
    return(Q->Front == Q->Rear);
}

// 将元素X压入队列
bool AddQ(Queue Q, ElementType X)
{
    if(IsFull(Q)){
        printf("队列已满");
        return false;
    }else{
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

// 删除并返回队列的头元素
ElementType DeleteQ(Queue Q)
{
    if(IsEmpty(Q)){
        printf("队列空");
        return ERROR;
    }else{
        Q->Front = (Q->Front + 1) % MaxSize;
        return Q->Data[Q->Front];
    }
}