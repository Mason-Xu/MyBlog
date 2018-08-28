// 直接插入排序
void InsertSort(ElemType A[] , int n){
    int i,j;
    for(int i = 2 ; i < n ; i++ ){                      // 依次将A[2]~A[n]插入到前面已排序序列
        if( A[i].key < A[i-1].key){                     // 若A[i]的关键码小鱼其前驱,需将A[i]插入有序表
            A[0] = A[i];                                // 复制哨兵,A[0]不存放元素
            for( j = i-1 ; A[0].key < A[j].key ; j--){  // 从后往前查找待插入元素
                A[j+1] = A[j];                          // 向后挪位
            }   
            A[j+1] = A[0];                              // 复制到插入位置
        }
    }
}

// 折半插入排序
void BInsertSort(ElemType A[], int n){
    int i,j,low,mid,high;
    for(i = 2; i <= n; i++){                    // 依次将A[2]~A[n]插入到前面已排序序列
        A[0] = A[i];                            // 将A[i]暂存到A[0]
        low = 1; high = i-1;                    // 设置折半查找范围
        while(low <= high){                     // 折半查找(默认递增)
            mid = (low + high)/2;               // 取中点
            if( A[mid].key > A[0].key ){        // 查找左半子表
                high = mid-1;
            }else{                              // 查找右半子表
                low = mid+1;
            }
            for( j = i-1 ; j >= high+1 ; --j){
                A[j+1] = A[j];                  // 统一后移元素,空出插入位置
            }   
            A[high+1] = A[0];                   // 插入操作
        }
    }
}


// 希尔排序
void ShellSort(ElemType A[], int n){
    // 对顺序表左希尔插入排序,本算法和直接插入排序对比,作了一下修改
    // 1. 前后记录位置的增量是dk,不是1
    // 2. r[0]只是暂存单元,不是哨兵 , 当j<=0时, 插入位置已到
    for( dk = n/2 ; dk >= 1; dk = dk/2){        // 步长变化
        for( i = dk+1 ; i <= n; ++i){
            if( A[i].key < A[i-dk].key){        // 需要将A[i]插入有序增量子表
                A[0] = A[i];                    // 暂存在A[0]
                for(j = i-dk ; j > 0 && A[0].key < A[j].key; j -= dk){
                    A[j+dk] = A[j];             // 记录后移,查找插入位置
                }
                A[j+dk] = A[0];                 // 插入
            } // if
        }
    }
}