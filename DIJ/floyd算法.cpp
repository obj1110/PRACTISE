#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 0x3fffff;
const int maxn = 510;
int n,m;
int d[maxn][maxn];

void floyd(){
	for(int k =0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(d[i][k] + d[k][j] < d[i][j] && d[i][k] != inf && d[k][j] != inf){
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
}



int main(){
	
	return 0;
}
