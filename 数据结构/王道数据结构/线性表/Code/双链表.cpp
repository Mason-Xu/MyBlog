typedef struct DNode{           // 定义双链表结点类型
    ElemType data;              // 数据域
    struct DNode *prior,*next;  // 前驱和后继指针
}DNode,*DLinkList;

// 双链表的插入操作
s->next = p->next;  // 将结点*e插入到结点*p之后
p->next->prior = s;
s->prior = p;
p->next = s;

// 双链表的删除操作
p->next = q->next;
q->next->prior = p;
free(q);