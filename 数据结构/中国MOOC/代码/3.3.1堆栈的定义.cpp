类型名称: 堆栈(Stack)  
数据对象集: 一个有0个或多个元素的有穷线性表  
操作集: 对于一个具体的长度为正整数的MaxSize的堆栈S ∈ Stack , 记堆栈中的任一元素 X ∈ ElementType  
堆栈的基本操作:  
1. Stack CreateStack(int MaxSize);  // 生成空堆栈,其最大长度为MaxSize
2. bool IsFull(Stack S);    // 判断堆栈S是否已满.若S中元素个数等于MaxSize时返回true,否则返回false;
3. bool Push(Stack short, ElementType X);   // 将元素 X 压入堆栈.若堆栈已满,返回false.否则将元素 X 插入到堆栈 S 栈顶处并返回true
4. ElementType Pop(Stack S);    // 删除并返回栈顶元素.若堆栈为空,返回错误信息,否则将栈顶数据元素从堆栈删除并返回