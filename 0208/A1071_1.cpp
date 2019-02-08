#include <iostream>
#include <map>
#include <cctype>
using namespace std;
map<string,int> mp;
int main(){
	string ans;
	getline(cin,ans);
	string tmp;
	for(int i=0;i<(int)ans.size();i++){
		if(tmp!=""&&(ans[i]==' ' || (isalpha(ans[i])==0 && isdigit(ans[i])==0))){
			mp[tmp]++;
			tmp.clear();
		}else if(isalpha(ans[i]) || isdigit(ans[i])){
			tmp.push_back(tolower(ans[i]));
		}
	}
	if(tmp!="")mp[tmp]++;
	int max_cnt=-1;
	string max_str,tmp_str;
	bool first=true;
	for(auto it: mp){
		if(first){
			first=false;
			tmp_str=it.first;
		}else{
			if(tmp_str>it.first) tmp_str=it.first;
		}
		if(it.second>max_cnt){
			max_cnt=it.second;
			max_str=it.first;
		}
	}
	if(max_cnt>1) cout<<max_str<<" "<<max_cnt;
	else cout<<tmp_str<<" 1";
	return 0;
}
--------------------- 
作者：whutshiliu 
来源：CSDN 
原文：https://blog.csdn.net/whutshiliu/article/details/82945000 
版权声明：本文为博主原创文章，转载请附上博文链接！
