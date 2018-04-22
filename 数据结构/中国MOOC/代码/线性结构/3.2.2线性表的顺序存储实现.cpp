typedef int Position;
// 这里的位置就是数组的下标，从0开始.  注意位序和下标的不同
typedef struct LNode *PtrToLNode;
struct LNode{
    ElementType Data[MAXSIZE];
    Posistion Last;
};
typedef PtrToLNode List;

// 初始化
List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

// 查找
#define ERROR = -1; // 将错误信息ERROR的值定义为任一负数

Position Find(List L, ElementType X)
{
    Position i = 0;
    while(i < = L->Last && L->Data[i] != X){
        i++;
    }
    if(i > L->Last){
        return ERROR;   // 如果没有找到,返回错误信息
    }else{
        return i;       // 找到后返回的是存储的位置
    }
}

// 在L的制定位序钱插入一个新元素 X,位序i元素的数组位置下标是i-1
bool Insert(List L, ElementType x, int i)
{   
    Position j;

    if(L->Last == MAXSIZE - 1){
        // 表空间已满,不能插入
        printf("表满");
        return false;
    }
    if(i < i || i > L->Last + 2){
        // 检查插入位序的合法性,是否在1~n+1.n为当前元素个数,即Last+1
        printf("位序不合法");
        return false;
    }
    for( j = L->Last; j >= i-1; j--){   // Last指向序列最后元素a
        L->Data[j+1] = L->Data[j];      // 将位序i以后的元素顺序向后移动
    }
    L->Data[i-1] = X;                   // 新元素插入地i位序,其数组下标为i-1
    L->Last++;                          // Last仍指向最后元素
    return true;
}

// 从L中删除位序为i的元素,数组下标为i-1
bool Delete(List L, int i)
{   
    Position j;

    if( i < 1 || i > L->Last + 1){  // 检查空表及删除位序的合法性
        printf("位序%d不存在元素", i);
        return false;
    }
    for(j = i; j <= L->Last; j++){
        L->Data[j-1] = L->Data[j];  // 将位序i+1及后面的元素向前移动
    }
    L->Last--;      // Last 仍指向最后元素
    return true;
}

