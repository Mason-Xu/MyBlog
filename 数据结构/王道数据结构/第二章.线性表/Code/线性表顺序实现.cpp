// 定义
#typedef MaxSize 50 // 最大长度
typedef struct
{
    ELemType data[MaxSize]; //  顺序表的元素
    int length;             // 顺序表的当前长度
}

// 顺序表插入操作
bool
ListInsert(Sqlist &L, int i; ElemType e)
{
    // 本算法实现将元素e插入到顺序表L的i位置
    if (i < 1 || i > L.length + 1)
    {
        return false; // 判断i的范围是否有效
    }
    if (L.length >= MaxSize)
    {
        return false; // 存储空间已满
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1]; // 将i后面的元素总体后移
    }
    L.data[i - 1] = e; // 位置i存入e
    L.length++;        // 线性表长度+1
    return true;
}

bool ListDelete(Sqlist &L, int i, ElemType &e)
{
    // 本算法实现删除顺序表L中第i个位置的元素
    if (i < 1 || i > L.length)
    { // 判断i的范围
        return false;
    }
    e = L.data[i - 1]; // 将被删除的元素赋值给e
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j]; // 将i位置后的元素前移
    }
    L.length--; // 线性表长度-1
    return true;
}

// 按值查找
int LocateElem(Sqlist L, ElemType e)
{
    // 本算法实现查找顺序表中值为e的元素,成功返回下表位序,否则返回0
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1; // 下标为i的元素值为e,返回其位序i+1
        }
    }
    return 0; // 退出循环,则表示查找失败
}

// 按值查找就是findElem()
int findElem(Sqlist L, ElemType x)
{
    int i = 0;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == x)
        {
            return i + 1;
        }
    }
    return 0;
}
