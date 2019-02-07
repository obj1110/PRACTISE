struct Node{
	int num;
	bool flag;
	char op;
};

string str;
map<char,int> op;
stack<node> st;
queue<node> q;

void Change(){
	//¡Ÿ ±±‰¡ø 
	double num;
	node temp;
	
	for(int i=0;i<str.length();){
		if(str[i] >='0' && str[i]<='9'){
			temp.flag = true;
			temp.num = str[i++] - '0';
			while(i<str.length() && str[i] >='0' && str[i]<='9'){
				temp.num = temp.num*10 +str[i]- '0';
				i++;
			}
			q.push(temp);
		}
		else{
			temp.flag = false;
			while(!s.empty() && op[str[i]] <= op[s.top().op]){
				q.push(s.top());
				s.pop();
			}
			temp.op  = str[i];
			s.push(temp);
			i++;
		}
		while(!s.empty()){
			q.push(s.top());
			s.pop();
		}
	}
}
