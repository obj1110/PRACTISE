//���������ַ��� getline(cin,string)
//����ֽ�ɺ��ʵĵ��ʣ���ͳһת��ΪСд��ĸ��ʽ����Ϊ ���ⲻҪ���Сд�������������ȫ�ǿ���ת��ΪСд�� 
//��map�����Ե��ʽ��м�����
//��������������ֵ��

//���⿼���ַ������������ַ������������ո���߷�������ĸ���ַ�ʱ��tmp���γ���һ������Ҫ���word��


//���һ�����Ե�Ӧ�ò���0������һ��������������
 
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
		//����Ȳ�������Ҳ������ĸ 
		else if(cts != 0){ 
			//����temp����tempӳ�䵽map����ȥ
			if(mp.find(temp) != mp.end())    mp[temp]++;
			else     mp[temp] = 1;
			temp.clear();
			cts = 0;
		}
		//�����������ֵķ����ַ���ĸ������Ĵ��� 
		else{
			continue;
		}
	}
	//Ѱ�ҳ������Ĵ��� 
	string gold_str;
	int cur_max = 0;
	for(auto it = mp.begin();it!=mp.end();it++){
		if(cur_max < it->second){
			cur_max = it->second;
			gold_str = it->first;
		}
	}
	//special û��һ���Ϸ��ĵ��ʣ�����������һ����̾�� 
	if(cur_max==0) {
		cout<<0<<endl;
		return 0; 
	}
	cout<<gold_str<<" "<<cur_max;
	
	return 0;
}
