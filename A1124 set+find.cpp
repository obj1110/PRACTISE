#include<iostream> 
#include<cstring>
#include<cstdlib>
#include<map>
#include<utility>
#include<set>
#include<algorithm> 

using namespace std;
const int maxn = 1050;
const int inf = 0x3fffffff;

int m,n,s;
map<int,string> int2str;
string temp;
set<string> st;
//map<int,string> winner;

//n  the total number of forwards, 
//m  the skip number of winners, 
//s  and the index of the first winner 
// (the indices start from 1).

void init(){
	scanf("%d%d%d",&m,&n,&s);
	getchar();
	for(int i=1;i<=m;i++){
		getline(std::cin,temp);
		int2str.insert(make_pair(i,temp));
	}

}

int main(){
	init();
	if(m<s){
		cout<<"Keep going..."<<endl;
		return 0;
	}
	
//	cout<<"........."<<endl;
	while(s<=m){
		if(st.empty()){
			st.insert(int2str[s]);
			cout<<int2str[s]<<endl;
//			cout<<int2str[s]<<" "<< s <<endl;
			s+=n;
		}
		else{
			if( st.count(int2str[s]) == 0){
				st.insert(int2str[s]);
				cout<<int2str[s]<<endl;
//				cout<<int2str[s]<<" "<< s <<endl;
				s += n;
			}
			else{
				s++;
			}
		}
	}
//	for(auto&x :st){
//		cout<<x<<endl;
//	}
	return 0;
}
