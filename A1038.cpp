#include<iostream> 
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

const int maxn = 10010;
string str[maxn];
//��С����������� 
bool cmp(string a,string b){
	return (a + b) < (b + a) ;
}

int main(){
	int n;
	scanf("%d",&n);
	for( int i=0 ; i<n ; i++ ){
		cin>>str[i]; 
	}
	//���� ,��Ҫ���Ǽ�������cmp���� 
	sort(str,str+n,cmp);
	//ƴ�� 
	string ans="";
	for(int i=0 ; i<n ; i++){
		ans += str[i];
	}
	//��Ϊ���ǰ����ܻ���ֺܶ��0
	//���Բ���һ��erase�Ϳ���ɾ�����0��
	//����Ҫ���ж��erase�ſ���ʵ��
	//����Ҳ������erase��һ������Ҳû�� 
	while( ans.size()!=0  &&  ans[0]=='0' ){
		ans.erase(ans.begin());
	}
	//���� 
	if(ans.size() == 0 ) cout<<0;
	else cout<<ans; 
	return 0;
}
