#include<iostream> 
#include<vector>
using namespace std;

bool isMirror = false;
vector<int> pre,post;
//���һ�����еĺ������� 
void getpost(int root,int tail){
	if(root > tail)  return;
	//��������ָ�� 
	int i =root +1, j = tail;
	if( !isMirror) {
		//�Զ��������������� 
		while(i <= tail && pre[root] > pre[i]) i++;
		while(j > root && pre[root] <= pre[j]) j--;
	}//�Ծ�����������
	else{
		while( i<= tail && pre[root] <= pre[i]) i++;
		while( j> root && pre[root] > pre[j] ) j--;
	} 
	//��һ�����зֽ��Ϊ�����֣�����ȷ�����ڵ�
	//����˵��Ҳ��һ���ݹ�Ĺ��̣� 
	if(i-j != 1) return;
	//���������� 
	getpost(root+1 ,j);
	//���������� 
	getpost(i,tail);
	//���ӵ���������������ȥ 
	post.push_back(pre[root]);
}

int main() {
	int n;
	cin >> n;
	pre.resize(n);
	for(int i=0; i<n;i++){
		cin>>pre[i];
	}
	getpost(0,n-1);
	if(post.size() != n){
		isMirror = true;
		post.clear();
		getpost(0,n-1);
	}
	if(post.size() == n){
		printf("YES\n%d",post[i]);
		for(int i =1;i<n;i++){
			printf(" %d",post[i]);
		}
		else{
			printf("NO");
		}
	}
	return 0;
}

