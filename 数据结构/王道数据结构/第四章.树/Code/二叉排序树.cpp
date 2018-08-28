// 二叉排序树的非递归算法  
BSTNode *BST_Search(BiTree T, ElemType key, BSTNode *&p){
    // 查找函数返回指向关键值为key的结点指针,若不存在,返回null
    p = NULL; // p指向被查找结点的双亲,用于插入与删除操作中
    while(T!=NULL && key != T->data){
        p = T;
        if(key < T->data) T = T->lchild;
        else T->rchild;
    }
    return T;
}

// 二叉排序树的插入
BST_Insert(BiTree &T,KeyType K){
    // 在二叉排序树T插入一个关键字为k的结点
    if(T == NULL){  // 原树为空,新插入的记录为根结点
        T = (BiTree)malloc(sizeof(BSTNode));
        T-key = k;
        T->lchild = T->rchild = NULL;   // 将左右孩子设置为NULL
        return 1;   // 返回1,表示插入成功
    }
    else if(k == T->key){   // 树种存在相同关键字的结点
        return 0;   
    }
    else if(k < T->key){    // 插入到T的左子树中
        return BST_Insert(T->lchild,k);
    }
    else{                   // 插入到T的右子树中
        return BST_Insert(T->rchild,k);
    }
}

// 二叉排序树的构造
void Create_BST(BiTree &T,KeyType str[],int n){
    // 用关键字数组str[] 建立一个二叉排序树
    T = NULL;   // 初始时T为空树
    int i = 0;
    while(i < n){   // 依次将每个元素插入
        BST_Insert(T , str[i]);
        i++;
    }
}