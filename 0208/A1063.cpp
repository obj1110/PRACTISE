// (the sets are numbered from 1 to N)

#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

set<int> st[55];

int main(){
  int n1,k,temp,num,a,b;
  // 
  scanf("%d",&n1);
  for(int i = 1 ; i <= n1 ; i++){
  	scanf("%d",&temp);
    while(temp--){
      scanf("%d",&num);
      st[i].insert(num);
    }
  }
  
  //tsts
//  for(int i=1;i<= n1;i++){
//  	for(auto it = st[i].begin() ; it!=st[i].end();it++ ){
//  		cout<<*it<<" " ;
//	  }
//	  cout<<endl;
//  } 
  
  //
  scanf("%d",&k);
  while(k--){
	scanf("%d %d",&a,&b);
	int count_common =0;
	//只要找到两个set中的相同的元素的个数，就可以推断出，两个set中的不同元素的总数目
	for(auto it = st[a].begin();it!= st[a].end();it++) {
		
//		if( *st[b].find(*it) != -1) count_common++; 

		if(st[b].find(*it) != st[b].end()) count_common++;
	}
//	printf("\n%d===%d\n",count_common, st[a].size() + st[b].size() - count_common );
	
	printf("%.1f%\n", (100.0 * count_common) / (1.0* ( st[a].size() + st[b].size()-count_common  )) ); 
  }
  
  //
  return 0;
} 
