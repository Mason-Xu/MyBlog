// 简单选择排序
void SelectSort(ElemType A[],int n){
    // 对表A作简单排序,A[]从0开始存放元素
    for(i = 0; i<n-1 ; i++){    // 一共进行n-1趟
        min = i;                // 记录最小元素位置
        for(j = i+1; j < n ; j++){  // 在A[i...n-1]中选择最小的元素
            if(A[i]<A[min]) min = j;    // 更新最小元素的位置
        if(min != i ) swap(A[i],A[min]);    // 与第i个位置交换
        } 
    }
}