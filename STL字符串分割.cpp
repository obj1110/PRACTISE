#include<iostream> 
#include<string>
#include<vector>
using namespace std;


vector<string> split(string str,string pattern){
	size_t pos;
	vector<string> result;
	str+=pattern;
	
	for(int i=0;i<str.size();i++){
//		find,��iλ�ÿ�ʼ����pattern��һ�γ��ֵ�λ�� 
		pos = str.find(pattern,i);
		//������λ���ǺϷ��� 
		if(pos < str.size()){
			//��ȡһ�����ַ��� 
			string s = str.substr(i,pos-i);
			result.push_back(s);
			i = pos+pattern.size() - 1;
		}
	}
	return result;
}

int main(){
	
}

