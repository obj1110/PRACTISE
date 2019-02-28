//������������ϵͳ��һ���ǽڵ�ı��ϵͳ��һ��������洢�ռ�ı��ϵͳ
//���ڽڵ���û��ɶ���壬����Ҫ����ļ�¼����������ռ�ÿռ䣬Ҳ����maxnum��index 


#include<iostream> 
#include<algorithm>
using namespace std;

const int maxn = 25;
int n;
char a[5];
char b[5];
int adj[maxn][2];
int isRoot[maxn]={0};

void init(){
	//Ҫ����������ǲ�����ĸ��
	//��������Ҫ���ַ�������ʽ�������룬ȷ�������ַ���֮���ٽ������ֵ�ת�� 
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%s %s",a,b); 
		if(a[0] == '-'){
			adj[i][0] = -1;	
		} 
		else{
			int ans = stoi(a);
			adj[i][0] = ans;
			isRoot[ans]++;
		}
		if(b[0] == '-'){
			adj[i][1] = -1;
		}
		else{
			int ans = stoi(b);
			adj[i][1] = ans;
			isRoot[ans]++;
		}
	} 	
}

int findRoot(){
	int i=0;
	while(isRoot[i] != 0) i++;
	return i;
}
//index��maxnum��������ռ�����Ķ���
//index�����㵱ǰ���������һ���ռ�
//����˵ans���Ǿ���˳����һ�����Ľڵ� 
int maxnum = -1;
int ans;

void InOrder(int root,int index){
//	cout<<index<<endl;
	if(index > maxnum){
		maxnum = index;
		ans = root;
	}
	if(adj[root][0] !=-1) InOrder(adj[root][0],index*2+1); 
//	cout<<root<<endl;
	if(adj[root][1] !=-1) InOrder(adj[root][1],index*2+2);
}
int main(){
	init();
	int root = findRoot();	
	
	InOrder(root,0);
	
	//maxnum�߾��������漰���Ĵ��̵Ĵ�С���
	//����maxnum����ľ��ǽڵ����
	//�ڱ����Ĺ����У����ϵĿ��ǵ�ǰ���漰���Ŀռ����ֵ
	//��������Ŀռ�����ֵ �� �ڵ�����ȣ�˵������ȫ������ 
	if(maxnum >= n){
		cout<<"NO "<<root;
	}
	else if(maxnum +1 ==  n){
		cout<<"YES "<<ans;	
	}
	return 0;
} 
