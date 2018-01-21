类型名称: 队列(Queue)
数据对象集: 一个有0个或多个元素的有穷线性表
操作集: 对于一个长度为正整数MaxSize的队列 Q ∈ Queue,记队列中任一元素 X ∈ ElementType
基本操作: 
1. Queue CreateQueue(int MaxSize);  // 生成空队列,其最大长度为MaxSize
2. bool IsFull(Queue Q);    // 判断队列Q是否已满
3. bool AddQ(Queue Q, ElementType X);   // 将元素X压入队列Q.队列已满,返回false,否则将数据元素X插入队列Q并返回true
4. bool IsEmpty(Queue Q);   // 判断队列Q是否为空,若是,返回true,否则false
5. ElementType Delete(Queue Q);     // 删除并返回队列头元素.若队列为空,返回错误信息,否则将队列头数据元素从队列删除并返回