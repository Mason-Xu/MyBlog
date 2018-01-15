List MakeEmpty(); // 初始化新的空线性表
ElementType FindKth(List L, int i); // 根据制定的位序,返回L中相应的元素ai
Position Find(List L, ElementType X); // 已知X,返回线性表中与X相同的第一个元素的位置,不存在则返回错误信息
bool Insert(:ist L, ElementType X, int i); // 插入X到L的指定位序,成功返回true,否则返回false
bool Delete(List L, int i);  // 从L中删除指定位序,数组下标为i-1,返回true和false
int Length(List L);  // 返回线性表L的长度 
