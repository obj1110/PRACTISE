#include<iostream>
#include<algorithm>

using namespace std;
int score[6];

struct item{
	int question[4];
	int total;
	int id;
	int rank;
	int fail; ///0��-1�Ĵ�����һ���ģ�����fail 
	int perfect;
}user[10050]={}; 

int cmp(item a,item b){
	if(a.total!=b.total) return a.total > b.total;
	//���a��b���ֶܷ࣬���ص���1 
	else if(a.perfect != b.perfect ) return a.perfect>b.perfect;
	else  return a.id < b.id;
} 

int main(){
	int N;//�û�����
	int K; //��������
	int M;//�ύ���� 
	scanf("%d %d %d",&N,&K,&M);
	for(int i=0;i<K;i++){
		scanf("%d",&score[i]);
	}
	int cts = 0;
	int a,b,c;
	
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&a,&b,&c);
		//ע�⣺���е�b��Ҫ��ȥ1��
		b  = b-1; 
		if(c==-1) c=0;
		
		if(i==0){
			for(int m=0;m<K;m++){
				user[cts].question[m] = -1;
			} 	
			//����ȫ����ʼ��Ϊ-1,������0����Ϊ��Щ�������û���ύ�� 
			user[cts].question[b] =c;
			user[cts].id = a;
			user[cts].total =0;
			user[cts].perfect = 0;
			user[cts].fail = 0;
			user[cts].rank =0;
			cts++;
			continue;
		}
		int j=0;
		//�������飬�ж������¼��û�������
		//������Ҫע�⣬��Щ�����Ǵ���û�б��ش���� 
		for(;j<cts;j++) {
			if(user[j].id == a){ 
				user[j].question[b] = (user[j].question[b]>c)?user[j].question[b]:c;
				break;
			}
		}
		//�ر�ע�⣬forѭ�������ǽ���ԭ�ж����ı������� 
		if(j == cts){
		//����һ����¼ 
			for(int m=0;m<K;m++){
				user[cts].question[m] = -1;
			} 	
			user[cts].question[b] = c;
            user[cts].id = a;
			user[cts].total = 0;
			user[cts].perfect = 0;
			user[cts].fail =0;
			cts++;
		} 
	}
	
	
	
	//Ҫ����sort�Լ�perfect �� fail ��total �ĸ�ֵ�����ˡ� 
	for(int i=0;i<cts;i++){
		for(int j=0;j<K;j++) {
			//-1�Ǳ�־����Ҫ��-1 
			if(user[i].question[j] == -1){
			}else{
				user[i].total += user[i].question[j];	
			}
			///////////////
			if(user[i].question[j] == score[j]){
				user[i].perfect++;	 
			}
			if(user[i].question[j]==0 || user[i].question[j]==-1) {
				user[i].fail++;
			}
		}
	}

//	cout<<"-------"<<endl;
//	printf(" id      total      perfect     fail\n");
//	for(int i=0;i<cts;i++) {
//		printf("%05d %d %d %d\n",user[i].id,user[i].total,user[i].perfect,user[i].fail);
//	} 
//	cout<<"-------"<<endl;
	
	//
	sort(user,user+cts,cmp);
	
	//��rank���и�ֵ
	int rank = 1;
	user[0].rank = 1;
	for(int i=1;i<cts;i++){
		if(user[i].total == user[i-1].total){
			user[i].rank = user[i-1].rank;
			rank++;	
		} 
		else if(user[i].total < user[i-1].total){
			user[i].rank = ++rank;
		}
	}
	
//	cout<<"!!!!!!" <<endl;
//	for(int i=0;i<cts;i++){
//		item ite=user[i];
//		cout<<ite.id<<" "<<ite.rank<<" "<<ite.total<<" "<<endl;
//		for(int j=0;j<K;j++){
//			cout<<ite.question[j]<<" ";
//		}
//		cout<<endl;
//	}

	//��� 
	
	
	for(int i=0;i<cts;i++){
		if(user[i].fail==K) continue;
		else {
			printf("%d %05d %d ",user[i].rank,user[i].id,user[i].total);
			for(int j=0;j<K;j++){
				if(user[i].question[j]==-1) printf("-");
				else printf("%d",user[i].question[j]); 
				if(j != K-1) printf (" ");
			}
		}
		if(i!=cts-1) printf("\n");
	}
	
	return 0;
} 
