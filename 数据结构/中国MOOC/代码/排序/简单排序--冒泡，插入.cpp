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

void Insertion_Sort( ElementType A[], int N )
{ /* 插入排序 */
     int P, i;
     int temp;
      
     for ( P=1; P<N; P++ ) {
         temp = A[P]; /* 取出未排序序列中的第一个元素*/
         for ( i=P; i>0 && A[i-1]>Tmp; i-- )
             A[i] = A[i-1]; /*依次与已排序序列中元素比较并右移*/
         A[i] = temp; /* 放进合适的位置 */
     }
}


void  Insertion_sort(ElementType A[].int n){
    for(int i = 1;i<N;i++){
        temp = A[i];
        int j = i;
        while(j>0 && A[j-1] > temp ){
            A[j] = A[j-1];
            j--;
        }
        A[j] = temp;
    }
}