//超过半数 才叫决定性颜色 
#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstdlib> 
#include<cstring>
#include<map>
 
using namespace std;

const int maxn = 0xffffff + 0x10;

map<int,int> mp;
int hash_table[maxn];

int main(){
	int m,n,temp;
	cin>>m>>n;
	
	memset(hash_table,0,maxn);

	
	int cur_max = 0;//当前最大的元素 
	int index = -1;//最大元素的index号 
	//m是列，n是行 
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++){
			scanf("%d",&temp);
			if(mp.find(temp) != mp.end()) mp[temp]++;
			else mp[temp] = 1;
			}
		}
	
	for(auto it=mp.begin(); it!= mp.end();it++){
		if(it->second > cur_max ){
			cur_max = it->second;
			index = it->first;
		} 
	}
	cout<<index;
	return 0;
}
