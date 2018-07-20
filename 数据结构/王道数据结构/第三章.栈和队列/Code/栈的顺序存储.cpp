#define MaxSize 50      // 定义栈中元素的最大个数
typedef struct{ 
    ElemType data[MaxSize]; // 存放栈中元素
    int top;    // 栈顶指针
}SqStack;

// 初始化 
void InitStack(&S){
    S.top = -1;      // 初始化栈顶指针
}

// 判栈空
bool StackEmpty(S){
    if(S.top = -1){
        return true;    // 栈空
    }else{
        return false;   // 不空
    }
}

// 进栈
bool Push(SqStack &S,ElemType x){
    if(S.top == MaxSize){   // 判断栈满
        return false;   
    }
    S.data[++S.top] = x;    // 指针+1,再入栈
    return true;
}

// 出栈
bool Pop(SqStack &S,ElemType x){
    if(S.top == -1){    // 判断栈空
        return false;
    }
    x = S.data[S.top--];     // 先出栈,再指针-1
    return true;
}

// 读栈顶元素
bool GetTop(SqStack &S,ElemType x){
    if(S.top == -1){    // 栈空报错
        return false;
    }
    x = S.data[S.top];
    return true;
}

// 栈的链式存储类型

typedef struct Linknode{
    ElemType data;   // 数据域
    struct Linknode *next;  // 指针域
}*LiStack;  // 栈类型定义