#include<iostream>
#include<queue>
struct node{
	int data;
	node* next;
};

node* Create(int Array[]) {
	//pre�ǹ���ָ��p��ǰ��ָ�룬Ȼ��head�����������ͷ���
	node *p,*pre,*head; 
	head = new head;
	head->next = NULL;
	//
	pre = head ;
	for(int i=0;i<sizeof(Array)/sizeof(Array[0]);i++){
		//����һ���սڵ� 
		p = new node;
		p->data = Array[i] ;
		p->next = NULL;
		//�������Ŀսڵ��������֮�� 
		pre->next = p;
		pre = p;
	}
	//���Ϻ����Ķ��� 
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
