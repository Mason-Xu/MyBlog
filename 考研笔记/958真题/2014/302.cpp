#include<iostream>
using namespace std;

struct node {
	int num;
	struct node *next;
};

struct node *reverse(struct node* head) {
	// head 头结点
	struct node *p, *temp1, *temp2;
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	p = head->next;
	head->next = nullptr;
	while (p != nullptr) {
		temp1 = p;
		head = p;
		temp2 = p;
		p = p->next;
		temp2->next = temp1;
		head->next = temp1;
	}
	return head;
}

int main302() {
	node n1,n2,n3;
	n1.num = 1;
	n1.next = &n2;
	n1.num = 2;
	n1.next = &n3;
	n1.num = 3;
	n1.next = nullptr;

	node *n = &n1;
	reverse(n);

	while (n != nullptr) {
		cout << n->num << endl;
		n = n->next;
	}

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* fnew(Node* L) {
	if (L = nullptr) {
		return NULL;
	}
	Node* newHead = L;
	Node* p = L->next;
	while (p != NULL) {		//将p结点移到链表最前方
		L->next = p->next;	// 头结点指向p的下一个结点
		p->next = L;
		L = p;
		p = L->next;
	}
	return L;

}

int main()
{
	
	Node *n1;
	Node *n2;
	Node *n3;
	n1->next = n2;
	n2->next = n3;

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;

	Node* n = n1;
	fnew(n);
	
	while (n!=NULL) {
		cout << n->data << endl;
		n = n->next;
	}
	system("pause");
	return 0;
}

