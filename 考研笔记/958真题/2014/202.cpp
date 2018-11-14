#include<iostream>
using namespace std;

struct Object {
	int a;
	int b;
};

Object& MyFunction(int a, int b) {
	// error 默认实参不在形参列表的结尾
	Object* o = new Object;
	o->a = a;
	o->b = b;
	return *o;
	// error 没有返回引用类型
}

int main202() {
	Object& MyFunction(int a , int  b);
	// error 默认实参不在形参列表的结尾
	Object& rMyObj = MyFunction(20, 5);
	// error 应输入表达式
	cout << "rMyObj.a = " << rMyObj.a << endl;
	delete &rMyObj;
	// 必须指向完整对象类型的指针
	system("pause");
	return 0;
}

//默认实参要写到列表末尾就是说，你a有默认值，需要写到b后面。或者两个都没有默认值。
//然后o是指针类型的，*o 解释了o对常量地址的引用即常量在内存中地址给o。
//应输入表达式是因为实参列表不完整 然后&rMyobj 才是对象类型，而不加&就是指针类型。