#include<iostream> 
#include<string>
#include<vector>
using namespace std;


vector<string> split(string str,string pattern){
	size_t pos;
	vector<string> result;
	str+=pattern;
	
	for(int i=0;i<str.size();i++){
//		find,从i位置开始查找pattern第一次出现的位置 
		pos = str.find(pattern,i);
		//如果这个位置是合法的 
		if(pos < str.size()){
			//获取一个子字符串 
			string s = str.substr(i,pos-i);
			result.push_back(s);
			i = pos+pattern.size() - 1;
		}
	}
	return result;
}

int main(){
	
}

