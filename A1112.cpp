//键盘的一部分被卡住了
//输出的就是重复的键和原来的句子 

//本题用下划线表示分割'_'


//首先确定出重复出现的键
//然后进行第二次遍历，将重复的键都进行改短 

//找到合适的字符之后，可以构造一些字符串，然后做字符串查找或者是分割的工作 


//问题来了，你的s之前的输出没有任何问题，那么你之后的输出即使有重复也不算数了
//所以，必须要用散列表，而且0表示之前没有遇到过这个字符，1表示错误，-1表示没毛病 


#include<iostream> 
#include<set>
#include<vector>
using namespace std;
int k;

int hashtable[256] = {0};
set<char> st; 
string s; 
int main(){
	cin>>k>>s;
	int len = s.length();
	for(int i=0;i<=len-k;i++){
		//j是增量
		int j;
		for(j=1; j<k && s[i+j] == s[i] ;j++);
		if(j==k){
			if(hashtable[s[i]] == 0) {
				hashtable[s[i]] = -1;	
				st.insert(s[i]);
				i += (k-1);
			}
		}
		else{
			if(hashtable[s[i]]==0){
				hashtable[s[i]] = 1;
			}
		}
	}
	for(auto &x:st){
		cout<<x; 
	}
	cout<<endl;
	for(int i=0;i<len;i++){
		if(hashtable[s[i]] == -1){
			cout<<s[i];
			i+=(k-1);
		}
		else{
			cout<<s[i];
		}
	}
	return 0;
}
