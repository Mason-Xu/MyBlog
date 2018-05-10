typedef struct{
    ElementType Data;
    int Parent;
}SetType;

// 查找某个元素所在的集合(用根结点表示)
int Find(SetType S[] ,ElementType X){
    // 在数组S[]中查找值为X的元素所属的集合
    // MaxSize是全局变量,为数组S的最大长度
    int i;
    for(i = 0; i < MaxSize && S[i].Data != X; i++){
        if(i >= MaxSize){
            return -1;  // 未找到X,返回-1
        }
    }
    for(;S[i].Parent >= 0; i = S[i].Parent);
    return i;   // 找到X所属集合,返回树根结点在数组S中的下标
}

// 集合的并运算
// 分别找到X1和X2两个元素所在几何数的根结点
// 如果他们不同根,则将其中一个根结点的父结点指针设置成另一个根结点的数组下标
void Union(SetType S[],ElementType X1,ElementType X2) {
    int Root1,Root2;
    Root1 = Find(S,X1);
    Root2 = Find(S,X2);
    if(Root1 != Root2){
        S[Root2].Parent = Root1;
    }
};
