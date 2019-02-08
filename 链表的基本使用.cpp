#include<iostream>
#include<queue>
struct node{
	int data;
	node* next;
};

node* Create(int Array[]) {
	//pre是工作指针p的前驱指针，然后head是整个链表的头结点
	node *p,*pre,*head; 
	head = new head;
	head->next = NULL;
	//
	pre = head ;
	for(int i=0;i<sizeof(Array)/sizeof(Array[0]);i++){
		//创建一个空节点 
		p = new node;
		p->data = Array[i] ;
		p->next = NULL;
		//将整个的空节点插入链表之中 
		pre->next = p;
		pre = p;
	}
	//符合函数的定义 
	return head;
}

int main(){
//	node* node1 = new node;
//	node* node2 = new node;
//	node* node3 = new node;
//	node* node4 = new node;
//	node* node5 = new node;
//	node1->data = 5;
//	node1->next = node2;
//	node2->data = 4;
//	node2->next = node3;
//	node3->data = 3;
//	node3->next = node4;
//	node4->data = 2;
//	node4->next = node5;
//	node5->data = 1;
//	node5->next = NULL;
}
