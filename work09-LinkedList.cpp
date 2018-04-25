#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <time.h> 
using namespace std;
struct node {
	int value;
	struct node *next;
};
typedef struct node Node;
Node *newNode(int data) {
	Node *node;
	node = (Node *)malloc(sizeof(Node));
	if (node == NULL) return NULL;
	node->value = data;
	node->next = NULL;
	return node;
}
Node *pushNode(Node *list, int data) {
	Node *node = newNode(data);//���ͷs�`�I
	if (list == NULL) list = node;// �[�J�Ĥ@�ӷs�`�I  
	else {
		Node *p = list;
		while (p->next != NULL) { p = p->next; }// ���o�̫�@�Ӹ`�I 
		p->next = node;
	}
	return list;
}
int main() {
	Node *list = NULL;
	int input;
	cout << "Please enter the number :";
	cin >> input;
	while (input != -1)
	{
		list = pushNode(list, input);
		cout << "Please enter the number :";
		cin >> input;
	}
	Node *pr = list;
	while (pr != NULL)
	{
		cout << pr->value << " ";
		pr = pr->next;
	}
	system("pause");
}