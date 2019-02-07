struct node{
	bool flag;
	int num;
	char op;
};
string str;
map<char,int> op;
stack<node> st;
queue<node> q;

void Change(){
	node temp; 
	for(int i =0;i< str.length();) {
		if(str[i]>= '0' && str[i]<= '9'){
			temp.flag  = false;
			int number = str[i++] - '0';
			while(i<str.length() && str[i]>= '0' && str[i]<= '9'){
				number = number*10 + str[i] - '0';
				i++;
			}
			temp.num = number;
			q.push(temp);
		}
		else{
			temp.flag = false;
			temp.op = str[i];
			while( i<str.length() && op[str[i]] <= op[st.top().op]){
				q.push(st.top());
				st.pop();
			}
			st.push(temp);
			i++;
		}
		while(!s.empty()){
			q.push(s.top()) ;
			s.pop();
		}
	}
}
