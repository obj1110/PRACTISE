//并查集 
#include<iostream> 
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
const int maxn = 10010; 
const int inf = 10010; 
int n,k,q,t,a,b;
set<int> birds;
set<int> trees[maxn];
set<int> temp;
set<int> ftrees[maxn];
//在一张照片中出现的鸟都属于同一棵树
//输出这个森林中鸟的最大数目 + 对于任意的两只鸟，他们是不是属于同一棵树

void init(){
	scanf("%d",&n);
	//n是照片数目 
	for(int i=0;i<n;i++){
		//k是要输入的个数 
		scanf("%d",&k);
		bool isexist = true;
		for(int j=0;j<k;j++){
			//输入的是这张照片中出现的鸟的序号都包括什么 
			scanf("%d",&t);
			trees[i].insert(t);
			birds.insert(t);
		}
	}
	int count = 0;
	// set的检查，包括加法和减法之类 
	for(int i=0 ; i<n ; i++) {
		for(int j=i+1 ; j<n ; j++){
			bool isOne = false;
			//开始列举集合1中的元素是不是在集合2中出现了
			for(auto ite = set[i].begin();ite != set[i].end();ite++) {
				//第一种情况就是没找到 
				if(set[j].find(*ite) == set[j].end()){
					continue;
					//进行下一个元素的比较 
				}
				//第二种情况就是找到了 
				else{
					isOne = true;
					break;
				}
			}
			//两个集合的合并 
			if(isOne == true){
				
			}
			//不要停止，因为i集合可能和其余的集合也属于一个树 
		}
		if(!isOne ){
			ftrees[count++] = trees[i];
		}
	} 
};
int main(){
	init();
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&a,&b);
	}
}
