#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100010
 
int N;
int num[maxn];
//按照从大到小进行排序 
bool cmp(int a,int b){
    return a>b;
}
 
int main(){
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&num[i]); 
    }
	//将数据扫描进来 
    sort(num,num+N,cmp);
    //进行数据的排序 
    for(i=0;1;i++){
        if(num[i]<=i+1){
            break;
        }
    }
    printf("%d\n",i);
    return 0;
}

