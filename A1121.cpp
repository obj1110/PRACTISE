#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 100000;
const int inf = 0x3fffffff;
int couple[100000]={0};
int party[100000] ={0};
int alone[100000] = {0};
set<int> st;

int main(){
	int n,a,b,temp;
	scanf("%d",&n);
	while(n){
		scanf("%d%d",&a,&b);
		couple[a] = b;
		couple[b] = a;
		n--;
	}
	scanf("%d",&n);
	while(n){
		scanf("%d",&temp);
		party[temp] = 1;
		n--;
	}
	for(int i =0;i<100000;i++) {
		if(party[i]== 1){
			if(party[couple[i]] == 1) continue;
			else if(couple[i] == 0 || party[couple[i]] == 0 ){
				st.insert(i);
			}
		}
	}
	cout<<st.size()<<endl;
	int size = st.size();
	for(auto& x:st){
		//注意一定要按照格式输出 
		printf("%05d",x);
		if(size>1 ){
			cout<<" ";
		}
		size--;
	}
	return 0;
}
