typedef int Position;
typedef struct SNode * PtrToSNode;
struct SNode{
    ElementType *Data;  // 存储元素的数组
    Position Top;   // 栈顶指针
    int MaxSize;    // 堆栈最大容量
};
typedef PtrToSNode Stack;

// 创建一个给定容量的空堆栈的函数
Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}


// 判断堆栈S是否已满
bool IsFull(Stack S)
{
    return(S->Top == S->MaxSize-1);
}

// 入栈操作 Push
bool Push(Stack S, ElementType X)
{
    if(IsFull(S)){
        printf("堆栈已满");
        return false;
    }else{
        S->Data[++(S->Top)] = X;
        return true;
    }
}

// 判断栈空
bool IsEmpty(Stack S)
{
    return(S->Top == -1);
}

// 出栈操作 Pop,删除并返回栈顶元素
ElementType Pop(Stack) 
{
    if(IsEmpty(S)){
        printf("堆栈空!")
        return ERROR;   // ERROR 是ElementType 的特殊值,标志错误
    }else{
        return(S->Data[(S->Top)--]);
    }
}

// TODO: 一个数组实现两个堆栈