#include<iostream> 
#include<stack>
using namespace std;

struct node{
	node* next;
	int data;
};
 
void traverse(node* root){
	if(root->next != NULL){
		traverse(root->next);
	} 
	else{
		printf("%d",root->data);
		return;
	}
}

int main(){
	
}
