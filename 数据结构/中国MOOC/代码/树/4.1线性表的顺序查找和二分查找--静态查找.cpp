Position SequentialSearch(list Tb1,ElementType K)
{   // 在顺序存储的表Tb1中查找关键字为k的数据元素,使用"哨兵"
    Position i;

    Tb1->Date[0] = K;   // 建立哨兵
    for(i = Tb1->Last; Tb1->Date[i]! = K; i--);
    return i;   // 查找成功返回数据元素所在的单元下表,查找不成功返回0
}

// 二分查找

#define NotFound -1 // 找不到则返回-1

Position BinarySearch(List Tb1,ElementType K)
{   // 在顺序存储的表中Tb1[1..Last]中查找关键字为K的数据元素
    Position left,right,mid;

    left = 1;   // 初始化左边界
    right = Tb1->Last;  // 初始化右边界
    while(left <= right){
        mid = (left + right) / 2;   // 计算中间元素坐标
        if(K < Tb1->Date[mid]){
            right = mid-1;  // 调整右边界
        }else if(k > Tb1->Date[mid]){
            left = mid + 1; // 调整左边界 
        }else{
            return mid; // 查找成功,返回数据元素的下标
        }
    }
    return NotFound;    // 返回查找不成功的标识
}