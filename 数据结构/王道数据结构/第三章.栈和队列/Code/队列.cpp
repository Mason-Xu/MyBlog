#define MaxSize 50  // 队列元素最大个数
typedef struct{
    ElemType data[MaxSize]; // 存放队列元素
    int front,rear; // 队头指针和队尾指针
}SqQueue;

// 循环队列操作

// 初始化
void InitQueue(&Q){
    Q.rear = Q.front =  0;  // 初始化队首，队尾指针
}

// 判队空
bool isEmpty(Q){
    if(Q.rear == Q.front){
        return true;
    }else{
        return false;
    }
}

// 入队
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MaxSize == Q.rear){
        return false;   //队满
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;    // 队尾指针+1取模
    return true;
}

// 出队
bool DeQueue(SqQueue &Q,ElemType x){
    if(Q.rear == Q.front){
        return false;   // 队空
    }
    x = Q.data[Q.front];    
    Q.front = (Q.front+1)%MaxSize;  // 队头指针+1取模
    return true;
}


// 链式存储
typedef struct{     // 链式队列结点
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

// 初始化

void InitQueue(LinkQueue &Q){
    Q.front = Q.rear =(LinkQueue*)malloc(sizeof(LinkNode)); // 建立头结点
    Q.front->next = NULL;
}

// 判空

bool IsEmpty(LinkQueue &Q){
    if(Q.front == Q.rear){
        return true;
    }else{
        return false;
    }
}

// 入队 . 建立新节点,将新节点插入到链尾的尾部,并改让Q.rear指向这个新插入的结点 . 若原队列为空,则Q.front也指向改结点.

void EnQueue(LinkQueue &Q,ElemType x){
    s = (LinkNode*)malloc(sizeof(LinkNode));    // 创建新节点,插入到链尾
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

// 出队

bool Dequeue(LinkQueue &Q,ElmeType &x){
    if(Q.front == Q.rear) return false; // 空队
    p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p){
        Q.rear = Q.front;   // 若队列中只有一个结点,删除后队空
    }
    free(p);
    return true;
}