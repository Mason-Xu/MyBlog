// 希尔排序
void  Shell_Sort(ElementType A[],int N){
    for( D = N / 2 ;  D > 0 ; D /= 2 ){     // 希尔增量序列
        for( P = D ; P < N ; P++ ){     // 直接插入排序
            Tmp = A[P];
            for( i = P; i >= D && A[i-D] > Tmp; i -= D ){
                A[i] = A[i-D];
            }
            A[i] = Tmp;
        }
    }
}  


void Shell_sort(ElementType A[],int N){
    for(D = N /2 ; D > 0 ; D /= 2 ){
        for(i=D ; i<N ; i++){
            temp = A[i];
            int j = i;
            while(i>0 && A[j-D] > temp){
                A[i] = A[i-D];
                i = i-D;
            }
            A[i] = temp;
        }
    }
}