//���̵�һ���ֱ���ס��
//����ľ����ظ��ļ���ԭ���ľ��� 

//�������»��߱�ʾ�ָ�'_'


//����ȷ�����ظ����ֵļ�
//Ȼ����еڶ��α��������ظ��ļ������иĶ� 

//�ҵ����ʵ��ַ�֮�󣬿��Թ���һЩ�ַ�����Ȼ�����ַ������һ����Ƿָ�Ĺ��� 


//�������ˣ����s֮ǰ�����û���κ����⣬��ô��֮��������ʹ���ظ�Ҳ��������
//���ԣ�����Ҫ��ɢ�б�����0��ʾ֮ǰû������������ַ���1��ʾ����-1��ʾûë�� 


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
		//j������
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
