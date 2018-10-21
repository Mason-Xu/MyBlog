// 冒泡排序
void BubbleSort(ElemType A[] , int n){
    // 用冒泡排序将序列A中的元素从小到大排序
    for(int i = 0 ; i < n-1 ; i++){
        flag = false;                       // 表示本趟冒泡排序是否发生交换的标志
        for(int j = n-1 ; j > i ; j--){     // 一趟冒泡排序
            if(A[j-1].key >A[j].key){       // 若为逆序
                swap(A[j-1],A[j]);          // 交换
                flag = true;                // flag设置为true,表示已交换
            }
        }
        if(flag == false){
            return ;
        }
    }
}


//冒泡排序
void Bubble_Sort(ElementType A[],int N){
    for( i = N-1;i>=0;i--){ // 执行N-1趟冒泡,将最大的移到最后
        flag = 0;
        for(j=0;j<i;j++){   // 一趟冒泡
            if(A[j] > A[j+1]){
                Swap(A[j],A[j+1]);
                flag = 1;    // 标识发生变化
            }
        }
        if(flag == 0) break;    // 全程无交换
    }
}

//冒泡排序
void BubbleSort(ElemType A[] , int n){
    // 用冒泡排序将序列A中的元素从小到大排序
    for(int i = 1; i <= n-1; i++) { // 循环n-1趟
		// 第i趟时从a[0]到a[n-i-1]都与他们下一个数比较 
		for(int j = 0; j < 5 - i; j++) {
			if(a[j]>a[j+1]) {	// 如果左边数更大,交换 
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}


// 快速排序 --- 递归
void QuickSort(ElemType A[] , int low ,int high){
    if(low < high){                             // 递归跳出的条件
        // Partition()就是划分操作,将表A[low...high]划分为满足上述条件的两个子表
        int pivotpos = Partition(A,low,high);   // 划分
        QuickSort(A,low,pivotpos-1);            // 依次对两个子表进行递归排序       
        QuickSort(A,pivotpos+1,high);          
    }
}

// 划分
int Partition(ElemType A[] , int low,int high){
    // 严版教材中的划分算法(一趟排序过程)
    ElemType pivot = A[low];    // 将当前表中第一个元素设为枢轴值,对表进行划分
    while(low<high){            // 循环跳出条件
        while(low<high && A[high].key >= pivot ) --high;
        A[low] = A[high];       // 将比枢轴值小的元素移动到左端
        while(low<high && A[low] <= pivot) ++low;
        A[high] = A[low];       // 将比枢轴值大的元素
    }
    A[low] = pivot;             // 枢轴值存放到最终位置
    return low;                 // 返回存放枢轴的最终位置
}


