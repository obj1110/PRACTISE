#include<iostream>
#include<cstring>
//男生的最低值和女生的最高值
using namespace std;
struct student{
	char name[15];
	char gender;
	char ID[15];
	int grade;
}ma,fe,temp;

void init(){
	fe.grade = -1; 
	ma.grade = 101;
}
int main(){
	init();
	int num;
	scanf("%d",&num);
	int flag1 = 0;
	int flag2 = 0;
	
	for(int i=0; i<num; i++){
		scanf("%s %c %s %d",temp.name,&temp.gender,temp.ID,&temp.grade);
		if((temp.gender=='F') && (temp.grade > fe.grade)){
			fe = temp;
			flag1 = 1;
			cout<<"---------------------"<<endl;
		}
		else if((temp.gender ==  'M') && (temp.grade < ma.grade)){
			ma = temp;
			flag2 = 1;
			cout<<"---------------------"<<endl;
		}
	}
	if(flag1 ==0){
		cout<<"Absent"<<endl;
	}
	else{
		cout<<fe.name<<" "<<fe.ID<<endl;
	}
	if(flag2 ==0){
		cout<<"Absent"<<endl;
	}
	else{
		cout<<ma.name<<" "<<ma.ID<<endl;
	}
	if(flag1== 0 || flag2 ==0){
		cout<<"NA";
	}
	else{
		printf("%d",fe.grade-ma.grade);
	}
	
	return 0;
}
