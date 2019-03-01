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
map<string,int> str2int;
map<int,string> int2str;
string temp;
map<string,int> winner;

//m  the total number of forwards, 
//n  the skip number of winners, 
//s  and the index of the first winner 
// (the indices start from 1).

void init(){
	scanf("%d%d%d",&m,&n,&s);
	for(int i=1;i<=m;i++){
		cin>>temp;
		str2int.insert(make_pair(temp,i));
		int2str.insert(make_pair(i,temp));
	}
}

int main(){
	init();
	if(m < s){
		cout<<"Keep going..."<<endl;
		return 0;
	}
	int count = 1;
	for( int i=s ; i<m ; ){
		if(winner.empty()){
			winner.insert(make_pair(int2str[i],count));
			count++;
			i += n;
		}
		else{
//			if(winner.count(int2str[i]) == 0 )
			if(winner[int2str[i]] == -1){
				winner.insert(make_pair(int2str[i],count));
				count++;
				i += n;
			}
			else{
				i++;
			}
		}
	}
	return 0;
}
