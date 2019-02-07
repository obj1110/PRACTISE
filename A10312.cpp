#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n,m,k;
bool v[1010][1010];
bool visit[1010];

void dfs(int node){
  visit[node] = true;
  for(int i = 1;i<=n;i++){
    if(visit[node]==false && v[node][i]==true) {
      dfs(i);
    }
  }
}

int main(){
  int m,k,a,b,c;
  scanf("%d%d%d",&n,&m,&k);
  
  memset(v,false,1010);
  
  for(int i=0;i<m;i++){
    scanf("%d%d",&a,&b);
    v[a][b] = v[b][a] = true;
  }
  
//  for(int i=0;i<1010;i++){
//  	for(int j =0;j<1010;j++){
//  		cout<<v[i][j]<<" ";
//	  }
//	  cout<<endl;
//  }

  for(int i=1 ; i<= k ; i++){
    memset(visit,false,1010);
    scanf("%d",&c);
    int cnt = 0;
    visit[c] = true;
    for(int j=1 ; j<=n ; j++){
      if( visit[j] == false ){
        dfs(j);
        cnt++;
      }
    }
    printf("%d\n",cnt-1);
  }
  return 0;
}
