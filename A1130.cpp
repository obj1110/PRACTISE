//������������������һ���ڽӱ����ʽ 

#include<iostream> 
#include<cstring>

using namespace std;
const int maxn = 25;
const int inf = 0xffffff; 

struct node{
	string data;
	int l,r;
}a[maxn];

//��Ϊ������ȱ�������������漰����һ��ջ 
string dfs(int root){
	//����Ѿ���������Ҷ�ӽڵ� 
	if(a[root].l == -1 && a[root].r == -1){
		return a[root].data;
	}
	//������������ǿյ� 
	if(a[root].l == -1 && a[root].r != -1){
		//ʱ��ע�⣬��Ҫ�������һ����׺���ʽ �������������ȱ�����Ȼ�����м䣬Ȼ���������� 
		return "(" + a[root].data + dfs(a[root].r) +")";
	}
	if(a[root].l != -1 && a[root].r == -1){
		return "(" + dfs(a[root].l) + a[root].data + ")";
	}
	if(a[root].l != -1 && a[root].r == -1){
		return "(" + dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
	}
}

int n;
int main(){
	// ����û��ָ�����ڵ㣬����have������Ҫ�� 
	int have[maxn] = {0};
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		//scanf����string���͵Ķ�ȡ��������� 
		cin >> a[i].data;
		getchar();
		scanf("%d %d",&a[i].l,&a[i].r);
		if(a[i].l != -1) have[a[i].l] = 1;
		if(a[i].r != -1) have[a[i].r] = 1;
	}
	
	int root=1;
	while(have[root] == 1 ) root++;
	
//	for(int i=1;i<=n ;i++){
//		cout<<"i :"<<i<<" "<< a[i].data <<" "<<a[i].l <<" "<<a[i].r<<endl;
//	}
	
	
	string ans = dfs(root);
	
	cout << ans;	
	return 0;
	
	
	// have��������þ�������ȷ�����ڵ��λ��
	// �����������ǰ������� ���� �Һ��ӵ�˳����е�
	// ���û�г��������ӻ����Һ����еĽڵ㣬һ���Ǹ��ڵ� 
 
 	// ������������ǿյ� 
	if(ans[0] == '(') {
		//һ���ǿ�ʼ��λ�ã�һ���ǽ�ȡ�ĳ��� 
		ans = ans.substr(1,ans.size() -2 ) ;
	}

}
