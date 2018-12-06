#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* fnew(Node* L) {
	if (L = nullptr) {
		return nullptr;
	}
	Node* p = L->next;
	Node* newHead = L;
	while (p != NULL) {			//将p结点移到链表最前方
		L->next = p->next;//头结点指向p的下一个结点
		p->next = newHead;	//p插入链表最前方
		newHead = p;		//链表新头结点更新为p
		p = L->next;//处理下一个结点，该结点位于头结点后
	}
	return newHead;
	

}

int main()
{
	Node n1, n2, n3;
	n1.data = 1;
	n1.next = &n2;
	n2.data = 2;
	n2.next = &n3;
	n3.data = 3;
	n3.next = nullptr;

	Node *n = &n1;
	fnew(n);

	while (n != nullptr) {
		cout << n->data << endl;
		n = n->next;
	}
	system("pause");
	return 0;
}

