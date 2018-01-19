typedef struct LNode *PtrToLNode;
typedef int ElementType;
struct LNode{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;    // 这里的位置是节点的地址
typedef PtrToLNode List;

// 求线性表L的长度
int Length(List L)
{
    Position p;
    int cnt = 0;    // 初始化计数器
    p = L;          // p指向表的第一个结点
    while(p){
        p = p->Next;
        cnt++;  // 当前p指向的是第cnt个结点
    }

    return cnt;
}

// 1. 查找
// 1.1 按序号查找
#define ERROR1 = -1;    // 一般定义为表中无法取得的值

ElementType FindKth(List L, int k)
{
    Position p;

    int cnt = 1; // 位序从1开始
    p = L;       // p指向第一个结点
    while(p && cnt < k){  
        p = p->Next;
        cnt++;
    }
    if((cnt == k) && p){    // cnt等于k且p指针存在
        return p->Data;
    }else{
        return ERROR1;
    }
}

// 1.2 按值查找

#define ERROR2 NULL; // 用空地址表示错误

Position Find(List L, ElementType X)
{
    Position p = L; // p指向第一个结点

    while( p && p->Data != X){
        p = p->Next;
    }

    // 直接return p 也可以
    if(p){
        return p;
    }else{
        return ERROR2;
    }
}