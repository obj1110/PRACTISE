//�ڿ���Ȩ��֮ǰ�����Ƚ�ÿһ���ڵ㶼���뿼�ǵķ�Χ����
//Ҳ����������Ӹ��ڵ㵽ÿһ��Ҷ�ڵ��·��

//27fen,��һ�������Ǹ�ʽ����
//�����˼·�����Ǳ������д��ӽڵ㵽���ڵ�����У�Ȼ���������ʱ������ж� 
#include<iostream> 
#include<vector>
#include<algorithm> 
using namespace std;
const int maxn  = 110;
int n,m,tw;
int w[maxn];
vector<int> node[maxn];

bool cmp(int a,int  b) {
	return w[a] > w[b];
}

void init(){
	int id,k,num;
	scanf("%d%d%d",&n,&m,&tw);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&id,&k);
		for(int j = 0;j<k;j++){
			scanf("%d",&num);
			node[id].push_back(num);
		}
		//���������Ե�ʣ����ȱ�����Ȩ�صĽڵ㣬����Ҫ��vector���б���
	}
	//��Ԫ�ؽ������� 
	for(int i=0; i<n;i++) {
		//�ر�ע�������д������������ 
		sort(node[i].begin(),node[i].end(),cmp);
	}
}

vector<int> temp; 
void BFS_root2leaf(int index){
	//������Ȩ�ص������ 
	//�����ӽڵ�϶���һ������ͬ�� 
	if(node[index].size() == 0){
		int temp_count = 0;
		for(int i=0;i<temp.size();i++){
			temp_count+= w[temp[i]];
		}
		if(temp_count + w[0] == tw){
			cout<<w[0]<<" ";
			for(int i=0;i<temp.size();i++) {
				cout<<w[temp[i]];
				if(i != temp.size() -1 ){
					cout<<" ";
				}
			}
			cout<<endl;
		}
		return;
		//��ʵ����A1053���Խ��Ӹ��ڵ㵽Ҷ�ӽڵ��ÿһ�����ж�����������
		//��Ȼ�϶�����DFS�ķ�ʽ��Ȼ����ǽ�temp��Ȩ�ؼ������ 
	} 
	//�������һ���ӽڵ������� 
	else{
		//��ͬ��DP���⣬����DFS����ÿһ���ڵ㶼��Ҫ���м���� 
		
		for(int i=0;i<node[index].size();i++){
			temp.push_back(node[index][i]);
			BFS_root2leaf(node[index][i]);
			temp.pop_back();
		}
		return;
	}
}

int main(){
	init();
	BFS_root2leaf(0);
	return 0;
}
