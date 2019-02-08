//读入输入字符； getline(cin,string)
//将其分解成合适的单词，并统一转化为小写字母形式；因为 本题不要求大小写的情况，所以完全是可以转化为小写的 
//用map容器对单词进行计数；
//输出结果并返回零值。

//此题考查字符串处理，遍历字符串，当遇到空格或者非数字字母的字符时，tmp即形成了一个符合要求的word。


//最后一个测试点应该不是0，而是一个更加特殊的情况
 
#include<iostream>
#include<string>
#include<cstdlib> 
#include<map>
#include<cctype>

using namespace std;

map<string,int> mp;

int main(){
	string str;
	getline(cin,str);
	
	string temp;
	int cts =0;
	for(int i=0 ;i< str.size() ;i++){
		if(isalpha(str[i]) || isdigit(str[i])){
			temp += tolower(str[i]);
			cts++;
		}
		//如果既不是数字也不是字母 
		else if(cts != 0){ 
			//处理temp，将temp映射到map里面去
			if(mp.find(temp) != mp.end())    mp[temp]++;
			else     mp[temp] = 1;
			temp.clear();
			cts = 0;
		}
		//对于连续出现的非数字非字母的情况的处理 
		else{
			continue;
		}
	}
	//寻找出现最多的次数 
	string gold_str;
	int cur_max = 0;
	for(auto it = mp.begin();it!=mp.end();it++){
		if(cur_max < it->second){
			cur_max = it->second;
			gold_str = it->first;
		}
	}
	//special 没有一个合法的单词，比如我输入一个感叹号 
	if(cur_max==0) {
		cout<<0<<endl;
		return 0; 
	}
	cout<<gold_str<<" "<<cur_max;
	
	return 0;
}
