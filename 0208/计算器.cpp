//1 中缀转后缀肯定是需要string
//2 即使是计算后缀，也是需要两个栈的，运算符栈和数字栈 

//--中缀转后缀-- 
//数字直接输出到后缀表达式的队列中 
//运算符需要经过stack的中转，低级、同级别的运算符会让高级运算符直接到后缀表达式
//高级运算符直接放在stack的上面  
//
//直到中缀输入式子已经空了以后，表达式栈中的元素才会进入后缀表达式 

//--数据结构的作用-- 
//queue的作用主要是作为后缀表达式的承担者
//stack一般用于在后缀表达式中处理操作符 或者是 在Cal中处理操作符
//mp主要是用于创建操作符的映射关系
//str，用于承接中缀表达式 


//--Cal--
//操作数 直接push stack
//操作符 从st中弹出两个操作数进行操作 
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
stack<node> st;// stack，操作符 
queue<node> q;//先进先出的队列 ，操作数 
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
			//输出到后缀表达式的队列中 
			q.push(temp);
		}
		else{
			temp.flag = false;
			while(!st.empty() && op[str[i]] <= op[st.top().op]){
				//如果是高级运算符的话，直接入栈就行 
				//如果是同级别运算符或者是低级运算符，栈中元素输出到后缀表达式的队列中 
				//之后呢，这个运算符再进栈
				//来了个+，所有的* / + - 都出去 ，输出到后缀表达式
				//来了个* ,所有的*都出去，输出到后缀表达式 
				
				//换句话说，只能保留比自己低的
//				op[str[i]] <= op[stack.top().op];
				q.push(st.top()) ;
				//运算符进入后缀表达式的第一条途径，来了一个低级或者是同级的元素 
				st.pop();
			}
			temp.op = str[i];
			st.push(temp);
			i++;
		}
		//运算符进入后缀表达式的第二条途径，来了一个低级或者是同级的元素 
		while(!st.empty()) {
			q.push(st.top());
			st.pop();
		}
	}
}
//不要忘记原来有的stack<node> st;
//不要忘记原来有的queue<node> q;
//不要忘记原来有的map<char,int> mp;
//不要忘记原来有的string str; 
double Cal(){
	double temp1;//临时操作数1 
	double temp2;//临时操作数2 
	node cur;//处理后缀表达式的元素 
	node temp;//后缀表达式中间计算结果的临时处理 
	// 
	while(!q.empty()){
		//获取后缀表达式的一个元素 
		cur = q.front();
		q.pop();
		//对于操作数的处理  
		if(cur.flag == true) st.push(cur);  
		//对于操作符的处理  
		else { 
			temp2 = st.top().num;
			st.pop();
			temp1 = st.top().num;
			st.pop();
			//表明这个东西是一个数字而不是一个符号 
			temp.flag = true; 
			//计算的过程 
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
	//不是一个表达式，而且没有停止标志，默认的表示就是空行或者是EOF 
	while(getline(cin,str),str!= "0"){
		for(string::iterator it= str.end();it!=str.begin();it--){
			for(*it == ' ') str.erase(it);
		}
		while(!st.empty()) st.pop();
		Change();
		printf("%0.2f\n",Cal());
	}
}
