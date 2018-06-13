
// 单链表定义
typedef struct LNode
{                       //定义单链表节点类型
    ElemType data;      // 数据域
    struct LNode *next; // 指针域
} LNode， *LinkList;

// 头插法建立单链表
LinkList CreateList1(LinkList &L)
{
    // 从表尾到表头逆向建立单链表，每次均在头结点之后插入元素
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    L - > next = NULL;
    scanf("%d", &x);
    while (X != 9999)
    {                                       // 输入9999表示结束
        s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// 尾插法建立单链表
ListList CreateList2(LinkList &L)
{
    // 从表头到表尾正向建立单链表,每次均在表尾插入
    int x; // 设定元素为整型
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L; //r为表尾指针
    scanf("%d", &x);  // 输入结点的值
    while (x != 9999)
    { // 输入9999结束
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL; // 尾结点指针置空
    return true;
}

// 按序号查找结点值
LNode *GetElem(LinkList L, iny L)
{
    // 本算法取出单链表L(带头结点)中第i位置的结点指针
    int j = 1;          // 计数
    LNode *p = L->next; //  头结点指针赋给p
    if (i == 0)
    {
        return L; //i为0,返回头结点
    }
    if (i < 1)
    {
        return NULL; // i无效,则返回NULL
    }
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找表结点
LNode *LocateElem(LinkList L, ElemType e)
{
    // 本算法查找单链表L(带头结点)中数据值为e的结点指针,否则返回NULL
    LNode *p = L->next;
    while (*p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 插入结点操作
s = (LinkList)malloc(sizeof(LNode)); // 创建插入结点
p = GetElem(L.i - 1);                // 查找插入位置的前驱结点
s->next = p->next;
p->next = s;

// 删除结点操作  , 找到前驱结点,执行删除操作
p = GetElem(L.i - 1); // 查找删除位置的前驱结点
q = p->next;          // 令q'指向删除结点
p->next = q->next;    // 将q结点从链中断开
free(q);              // 师范结点的存储空间

// 也可以删除后继节点来实现 , 将后继节点的值赋予本身,然后删除后继节点
q = p->next;             // 令q指向*p的后继节点
p->data = p->next->data; // 与后继节点交换数据域
p->next = q->next;       // 将*q结点从链中断开
free(q);                 // 释放存储空间
