typedef struct HeapStruct *MaxHeap;
struct HeapStruct{
    ElementType *Elements;  // 存储堆元素
    int Size;   // 堆当前的元素个数
    int Capacity; // 堆得最大容量
};

// 创建容量为MaxSize的空堆
MaxHeap Create(int MaxSize){
    MaxHeap H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxSize+1)*sizeof(sizeof(ElementType)));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData;
        // 定义哨兵为大于堆中所有可能元素的值,便于以后更快操作
    return H;
}

// 最大堆的插入 将元素item插入最大堆H中牟其中H->ElementType[0]已经定义成哨兵
void Insert(MaxHeap H,ElementType item){
    int i;
    if( IsFull(H)){
        printf("最大堆已满");
        return;
    }
    i = ++H->Size;  // i指向插入后堆中的最后一个元素的位置
    for( ; H->Elements[i/2] < item;i/=2){
        H->Elements[i] = H->Elements[i/2];  // 向下过滤结点
        // Elements[0]是哨兵元素,不小于堆中的最大元素,便于控制循环结束
    } 
    H->Elements[i] = item;  // 将item插入
}

// 最大堆的删除
// 取出根结点(最大值)元素,同时删除堆得一个结点
// 1. 将最后结点
ElementType DeleteMax(MaxHeap H){
    // 从最大堆H中取出键值为最大的元素,并删除一个结点
    int Parent,Child;
    ElementType MaxItem,temp;
    if(IsEmpty(H)){
        printf("最大值已空");
        return;
    }
    MaxItem = H->Elements[1];   // 取出根结点最大值
    temp = H->Elements[H->Size--];  // 用最大堆中最后一个元素从根结点开始向上过滤下层结点
    for(Parent = 1;Parent * 2 <= H->Size ; Parent = Child){
        Child = Parent * 2;
        if(Child != H->Size) && (H->Elements[Child] < H->Elements[Child+1]){
            Child++;    // Child指向左右子结点的较大者
        }
        if(temp >= H->Elements[Child]){
            break;
        }else{  // 移动temp元素到下一层
            H->Elements[Parent] = H->Elements[Child];
        }
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}