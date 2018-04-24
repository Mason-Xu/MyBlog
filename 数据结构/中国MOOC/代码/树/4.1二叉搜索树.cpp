typedef struct TNode *Position;
typedef Position BinTree;   // 二叉树类型
struct TNode{   // 树节点定义
    ElementType Data;   //  节点数据
    BinTree Left;   //指向左子树
    BinTree Right;  //指向右子树
};

// Find
Position Find(ElementType X,BinTree BST){
    if( !BST ) return null;   // 树为空
    if(X>BST->Data){
        return Find(X,BST->Right);  // 在右子树中继续查找
    }else if(X < BST->Data){
        return Find(X,BST->Left)    // 在左子树中继续查找
    }else{  // X == BST->Data
        return BST; // 查找成功,返回结点的找到结点的地址
    }
}

// 非递归 尾递归 迭代函数 Find

Position IterFind(ElementType X,BinTree BST){
    while( BST ){}
        if(X > BST->Data){
            BST = BST->Right;   // 向右子树中移动,继续查找
        }else if(X < BST->Data){
            BST = BST->Left;    // 向左子树中移动,继续查找
        }else{  // X == BST->Data
            return BST; // 查找成功,返回结点的找到节点的地址
        }
    }
    return null;   // 查找失败,返回null
}

// 查找最小元素,在最左子树的端结点 (递归函数)
Position FindMin(BinTree BST){
    if(!BST){
        return null;   // 树空,返回null
    }else if(!BST->Left){
        return BST; // 返回最左叶结点并返回
    }else{
        return FindMin(BST->Left);   //沿左分支继续查找 
    }
}


// 查找最大元素,在最右子树的端结点 (迭代函数)
Position FindMax(BinTree BST){
    if(BST){
        while(BST->Right){
            BST = BST->Right;   // 沿右分支继续查找,直到最右叶结点
        }
    }
    return BST;

}

// 将元素X插入二叉搜索树
BinTree Insert( ElementType X, BinTree BST){
    if(!BST){   // 若原树为空,生成并返回一个结点的二叉树
        BST = malloc(sizeof(struct TreeNode));
        BST->Data = X;
        BST->Left = BST->Right = null;
    }else{
        if(X < BST->Data){
            BST->Left = Insert(X,BST->Left);    // 递归插入左子树
        }else if(X > BST->Data){
            BST->Right = Insert(X,BST->Right);  // 递归插入右子树
        }// else x已经存在,什么都不做
    }
    return BST;
}


// 删除元素,找右子树最小元素,左子树最大元素

BinTree Delete( ElementType X,BinTree BST){
    Position Tmp;
    if(!BST){
        printf("要删除的元素未找到");
    }else if(X < BST->Data){
        BST->Left = Delete(X,BST->Left);
    }else if(X > BST->Data){
        BST->Right = Delete(X,BST->Right);
    }else{  // 找到要删除结点
        if(BST->Left && BST->Right){    // 被删除结点有左右子节点
            Tmp = Find(BST->Right); // 在右子树中找最小的元素填充删除结点
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Data,BST->Right);  // 在删除结点的右子树中删除最小元素
        }else{  // 被删除结点有一个或无子结点
            Tmp = BST;
            if(!BST->Left){ // 有右孩子或无子结点
                BST = BST->Right;
            }else if(!BST->Right){  // 有右孩子或无子结点
                BST = BST->Left;    
            }
            free(Tmp);
        }
    }
    return BST;
}