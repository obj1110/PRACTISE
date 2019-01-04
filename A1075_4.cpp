#include<iostream>
#include<algorithm>

using namespace std;
int score[6];

struct item{
	int question[4];
	int total;
	int id;
	int rank;
	int fail; ///0和-1的待遇是一样的，都是fail 
	int perfect;
}user[10050]={}; 

int cmp(item a,item b){
	if(a.total!=b.total) return a.total > b.total;
	//如果a比b的总分多，返回的是1 
	else if(a.perfect != b.perfect ) return a.perfect>b.perfect;
	else  return a.id < b.id;
} 

int main(){
	int N;//用户总数
	int K; //问题总数
	int M;//提交总数 
	scanf("%d %d %d",&N,&K,&M);
	for(int i=0;i<K;i++){
		scanf("%d",&score[i]);
	}
	int cts = 0;
	int a,b,c;
	
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&a,&b,&c);
		//注意：所有的b都要减去1；
		b  = b-1; 
		if(c==-1) c=0;
		
		if(i==0){
			for(int m=0;m<K;m++){
				user[cts].question[m] = -1;
			} 	
			//首先全部初始化为-1,而不是0，因为有些问题根本没有提交过 
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
		//遍历数组，判断这个记录有没有输入过
		//而且你要注意，有些问题是从来没有被回答过的 
		for(;j<cts;j++) {
			if(user[j].id == a){ 
				user[j].question[b] = (user[j].question[b]>c)?user[j].question[b]:c;
				break;
			}
		}
		//特别注意，for循环里面是进行原有东西的遍历！！ 
		if(j == cts){
		//增加一条记录 
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
	
	
	
	//要进行sort以及perfect 和 fail 和total 的赋值操作了。 
	for(int i=0;i<cts;i++){
		for(int j=0;j<K;j++) {
			//-1是标志，不要加-1 
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
	
	//给rank进行赋值
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

	//输出 
	
	
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
