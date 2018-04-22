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

// 插入
#define ERROR3 NULL  // 用空地址表示错误

List Insert(List L, ElementType X, int i)
{
    Position tmp, pre;

    tmp = (Position)malloc(sizeof(struct LNode));   // 申请,填装结点
    tmp->Data = X;
    if(i == 1){ // 新结点在表头指针
        tmp->Next = L;
        return tmp; //  返回新表头指针
    }else{
        // 查找位序为i-1的节点
        
        int cnt = 1;    // 位序从1开始
        pre = L;    // pre指向L的第一个结点
        while(pre && cnt < i-1){
            pre = pre->Next;
            cnt++;
        }
        if(pre == NULL || cnt != i-1){
            printf("插入位置参数错误\n");
            free(tmp);
            return ERROR3;
        }else{  // 找到待插结点的前一个结点pre
            //插入新结点并返回表头L
            tmp->Next = pre->Next;
            pre->Next = tmp;
            return L;
        }
    }
}

// 带头结点的链式表的插入
bool Insert(List L, ElementType X, int i)
{   // 这里默认L有头结点
    Position tmp, pre;
    int cnt = 0;

    // 查找位序为i-1的结点
    pre = L;    // pre指向表头
    while(pre && cnt < i-1){
        pre = pre->Next;
        cnt++;
    }
    if(pre == NULL || cnt != i-1){  // 所找结点不在L中
        printf("插入位置参数错误!");
        return false;
    }else{  // 找到了待插结点的前一个结点pre,若i为1,pre就指向表头
        // 插入新结点
        tmp = (Position)malloc(sizeof(struct LNOde));   // 申请,填装结点
        tmp->Data = X;
        tmp->Next = pre->Next;
        pre->Next = tmp;
        return true;
    }
}

// 带头结点的链式表的删除
bool Delete(List L, int i)
{   // 这里默认L有头结点
    Position tmp, pre;
    int cnt = 0;

    // 查找位序为i-1的结点
    pre = L;    // pre 指向表头
    while(pre && cnt < i-1){
        pre = pre->Next;
        cnt++;
    }
    if(pre == NULL || cnt != i-1 || pre->Next == NULL){
        // 所找结点或位序为i的结点不在L中
        printf("插入位置参数错误!");
        return false;
    }else{  // 找到待删结点的前一个结点pre
        // 将结点删除
        tmp = pre->Next;
        pre->Next = tmp->Next;
        free(tmp);
        return true;
    }
}
