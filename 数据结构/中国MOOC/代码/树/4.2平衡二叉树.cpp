typedef struct AVLNode *Position;
typedef Position AVLTree; // AVL树类型
struct AVLNode{
    ElementType Data;   // 结点数据
    AVLTree Left;   // 指向左子树
    AVLTree Right;  // 指向右子树
    int Height; // 树高
};

int Max(int a,int b){
    return a > b ? a : b;
}

AVLTree SingleLeftRotation(AVLTree A){ // 左单旋
    // 注意: A必须有一个左子结点B
    // 将A与B做左单旋,更新A与B的高度.返回新的根结点B

    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max(GetHeight(A->Left),GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Left),GetHeight(B->Right)) + 1;
    
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A){
    // 注意:A必须有一个左子结点B,且B必须有一个右子结点C
    // 将A,B,C做两次单旋,返回新的根结点C

    // 将B与C做右单旋,C被返回
    A->Left = SingleLeftRotation(A->Left);
    // 将A与C做一次左单旋,返回
    return SingleLeftRotation(A);
}

AVLTree Insert(AVLTree T,ElementType X){
    // 将X插入AVL树中,并且返回调整后的AVL树
    if(!T){ // 若插入空树,则新建包含一个结点的树
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Left = T->Right = NULL;
        T->Height = 0;
    }else if(X < T->Data){  // 如果插入X小于根结点
        // 插入T的左子树
        T->Left = Insert(T->Left,X);    // 递归
        // 如果需要左旋
        if(GetHeight(T->Left)-GetHeight(T->Right) == 2){
            if(X < T->Left->Data){
                SingleLeftRotation(T);  // 左单旋
            }else{
                DoubleLeftRightRotation(T); // 左右双旋
            }
        }
    }else if(X > T->Data){  // 如果插入X大于根结点
        // 插入T的右子树
        T->Right = Insert(T->Right,X);    // 递归
        // 如果需要右旋
        if(GetHeight(T->Left)-GetHeight(T->Right) == -2){
            if(X > T->Right->Data){
                SingleRightRotation(T);  // 右单旋
            }else{
                DoubleRightLeftRotation(T); // 右左双旋
            }
        }
    }
    // else if X == T->Data 无需插入
    // 别忘了更新树高
    T->Height = Max(GetHeight(T->Left),GetHeight(T->Right))+1;
    return T;
}