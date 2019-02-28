//在考虑权重之前，首先将每一个节点都带入考虑的范围里面
//也就是输出，从根节点到每一个叶节点的路径

//27fen,有一个特例是格式错误
//本题的思路，就是遍历所有从子节点到根节点的序列，然后在输出的时候进行判断 
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
		//由于输出的缘故，优先遍历大权重的节点，所以要对vector进行遍历
	}
	//对元素进行排序 
	for(int i=0; i<n;i++) {
		//特别注意这里的写法！！！！！ 
		sort(node[i].begin(),node[i].end(),cmp);
	}
}

vector<int> temp; 
void BFS_root2leaf(int index){
	//不考虑权重的情况下 
	//到达子节点肯定是一个死胡同了 
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
		//其实可以A1053可以将从根节点到叶子节点的每一个队列都遍历出来，
		//当然肯定是用DFS的方式，然后就是将temp的权重计算求和 
	} 
	//如果存在一个子节点的情况下 
	else{
		//不同于DP问题，这种DFS对于每一个节点都是要进行计算的 
		
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
