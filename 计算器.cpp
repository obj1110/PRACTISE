//1 ��׺ת��׺�϶�����Ҫstring
//2 ��ʹ�Ǽ����׺��Ҳ����Ҫ����ջ�ģ������ջ������ջ 

//��׺ת��׺������ֱ���������׺���ʽ�Ķ����� 
//�������Ҫ����stack����ת���ͼ���ͬ�������������ø߼������ֱ�ӵ���׺���ʽ
//�߼������ֱ�ӷ���stack������  
//
//ֱ����׺����ʽ���Ѿ������Ժ󣬱��ʽջ�е�Ԫ�زŻ�����׺���ʽ 

#include<iostream> 
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<stack> 
#include<map>
#include<queue>

using namespace std;

struct node{
	double num;
	char op;
	bool flag;
};

string str;
stack<node> s;// stack�������� 
queue<node> q;//�Ƚ��ȳ��Ķ��� �������� 
map<char,int> op;

void Change(){
	double num;
	node temp;
	for(int i=0;i<str.length();){
		if(str[i] >= '0' && str[i]<='9'){
			temp.flag = true;
			temp.num = str[i++] - '0';
			while( i< str.length() && str[i] >='0' && str[i] <='9'){
				temp.num = temp.num*10 + str[i]- '0';
				i++;
			}
			//�������׺���ʽ�Ķ����� 
			q.push(temp);
		}
		else{
			temp.flag = false;
			while(!s.empty() && op[str[i]] <= op[s.top().op]){
				//����Ǹ߼�������Ļ���ֱ����ջ���� 
				//�����ͬ��������������ǵͼ��������ջ��Ԫ���������׺���ʽ�Ķ����� 
				//֮���أ����������ٽ�ջ
				//���˸�+�����е�* / + - ����ȥ ���������׺���ʽ
				//���˸�* ,���е�*����ȥ���������׺���ʽ 
				
				//���仰˵��ֻ�ܱ������Լ��͵�
//				op[str[i]] <= op[stack.top().op];
				q.push(s.top()) ;
				//����������׺���ʽ�ĵ�һ��;��������һ���ͼ�������ͬ����Ԫ�� 
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
		//����������׺���ʽ�ĵڶ���;��������һ���ͼ�������ͬ����Ԫ�� 
		while(!s.empty()) {
			q.push(s.top());
			s.pop();
		}
	}
}

int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	//����һ�����ʽ������û��ֹͣ��־��Ĭ�ϵı�ʾ���ǿ��л�����EOF 
	while(getline(cin,str),str!= "0"){
		for(string::iterator it= str.end();it!=str.begin();it--){
			for(*it == ' ') str.erase(it);
		}
		while(!s.empty()) s.pop();
		Change();
		printf("%0.2f\n",Cal());
	}
}
