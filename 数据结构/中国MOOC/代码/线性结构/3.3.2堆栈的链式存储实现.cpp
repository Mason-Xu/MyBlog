typedef struct SNode * PtrToSNode;
struct SNode{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

// 构建一个堆栈的头结点 ,返回该节点指针,栈底结点的Next为NULL
Stack CreateStack()
{   
    Stack S;

    S = malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

// 判断堆栈S是否为空, 若是返回true ,否则返回false
bool IsEmpty(Stack S)
{
    return(S->Next == NULL);
}

// Push 将元素X压入堆栈S
bool Push(Stack S, ElementType X)
{
    PtrToSNode TmpCell; // 临时指针
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}

// 删除并返回堆栈S的栈顶元素
ElementType Pop(Stack S)
{
    PtrToSNode FirstCell;
    ElementType TopElem;

    if(IsEmpty(S)){
        printf("堆栈空!");
        return ERROR;
    }else{
        FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem; // 返回栈顶元素
    }
}

// TODO: 堆栈应用: 表达式求值
// TODO: 使用堆栈求后缀表达式