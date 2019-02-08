//1 ��׺ת��׺�϶�����Ҫstring
//2 ��ʹ�Ǽ����׺��Ҳ����Ҫ����ջ�ģ������ջ������ջ 

//--��׺ת��׺-- 
//����ֱ���������׺���ʽ�Ķ����� 
//�������Ҫ����stack����ת���ͼ���ͬ�������������ø߼������ֱ�ӵ���׺���ʽ
//�߼������ֱ�ӷ���stack������  
//
//ֱ����׺����ʽ���Ѿ������Ժ󣬱��ʽջ�е�Ԫ�زŻ�����׺���ʽ 

//--���ݽṹ������-- 
//queue��������Ҫ����Ϊ��׺���ʽ�ĳе���
//stackһ�������ں�׺���ʽ�д�������� ������ ��Cal�д��������
//mp��Ҫ�����ڴ�����������ӳ���ϵ
//str�����ڳн���׺���ʽ 


//--Cal--
//������ ֱ��push stack
//������ ��st�е����������������в��� 
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
stack<node> st;// stack�������� 
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
			while(!st.empty() && op[str[i]] <= op[st.top().op]){
				//����Ǹ߼�������Ļ���ֱ����ջ���� 
				//�����ͬ��������������ǵͼ��������ջ��Ԫ���������׺���ʽ�Ķ����� 
				//֮���أ����������ٽ�ջ
				//���˸�+�����е�* / + - ����ȥ ���������׺���ʽ
				//���˸�* ,���е�*����ȥ���������׺���ʽ 
				
				//���仰˵��ֻ�ܱ������Լ��͵�
//				op[str[i]] <= op[stack.top().op];
				q.push(st.top()) ;
				//����������׺���ʽ�ĵ�һ��;��������һ���ͼ�������ͬ����Ԫ�� 
				st.pop();
			}
			temp.op = str[i];
			st.push(temp);
			i++;
		}
		//����������׺���ʽ�ĵڶ���;��������һ���ͼ�������ͬ����Ԫ�� 
		while(!st.empty()) {
			q.push(st.top());
			st.pop();
		}
	}
}
//��Ҫ����ԭ���е�stack<node> st;
//��Ҫ����ԭ���е�queue<node> q;
//��Ҫ����ԭ���е�map<char,int> mp;
//��Ҫ����ԭ���е�string str; 
double Cal(){
	double temp1;//��ʱ������1 
	double temp2;//��ʱ������2 
	node cur;//�����׺���ʽ��Ԫ�� 
	node temp;//��׺���ʽ�м����������ʱ���� 
	// 
	while(!q.empty()){
		//��ȡ��׺���ʽ��һ��Ԫ�� 
		cur = q.front();
		q.pop();
		//���ڲ������Ĵ���  
		if(cur.flag == true) st.push(cur);  
		//���ڲ������Ĵ���  
		else { 
			temp2 = st.top().num;
			st.pop();
			temp1 = st.top().num;
			st.pop();
			//�������������һ�����ֶ�����һ������ 
			temp.flag = true; 
			//����Ĺ��� 
			if(cur.op == '+') temp.num = temp1+ temp2;
			else if(cur.op=='-') temp.num = temp1 - temp2;
			else if(cur.op == '*') temp.num = temp1 * temp2;
			else if(cur.op == '/') temp.num = temp1/temp2;
			st.push(temp);
		} 
	}
	return st.top().num;
}


int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	//����һ�����ʽ������û��ֹͣ��־��Ĭ�ϵı�ʾ���ǿ��л�����EOF 
	while(getline(cin,str),str!= "0"){
		for(string::iterator it= str.end();it!=str.begin();it--){
			for(*it == ' ') str.erase(it);
		}
		while(!st.empty()) st.pop();
		Change();
		printf("%0.2f\n",Cal());
	}
}
