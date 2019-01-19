#include<iostream> 
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

const int maxn = 10010;
string str[maxn];
//从小到大进行排序 
bool cmp(string a,string b){
	return (a + b) < (b + a) ;
}

int main(){
	int n;
	scanf("%d",&n);
	for( int i=0 ; i<n ; i++ ){
		cin>>str[i]; 
	}
	//排序 ,不要忘记加上最后的cmp函数 
	sort(str,str+n,cmp);
	//拼接 
	string ans="";
	for(int i=0 ; i<n ; i++){
		ans += str[i];
	}
	//因为你的前面可能会出现很多的0
	//所以不是一次erase就可以删除这个0的
	//必须要进行多次erase才可以实现
	//但是也不可以erase到一个数字也没有 
	while( ans.size()!=0  &&  ans[0]=='0' ){
		ans.erase(ans.begin());
	}
	//特情 
	if(ans.size() == 0 ) cout<<0;
	else cout<<ans; 
	return 0;
}
