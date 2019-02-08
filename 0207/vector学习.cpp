#include<iostream> 
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<time.h>
#include<utility> 

using namespace std;
const int maxn = 1000100;
typedef long long ll;

int main(){
	//两种二维数组 
	vector<int> ve[100]; //二维均可变 
	vector<vector<int>> name; //只有一个维度可以改变
	
	int size  = 10;
	int value  = 5 ;
	vector<int> vi(size,value);
	for(int i =1;i<=3 ;i++) {
		vi.push_back(i);
	}
	
	
	vi.pop_back();
	vi.insert(vi.begin()+2,-1);
	vi.insert(vi.begin()+2,-5);
	
	vi.erase(vi.begin() +9); //删除的是vi[9]的元素，因为vi.begin本身对应的是vi[0] 
	vi.erase(vi.begin()+1,vi.begin()+3); //范围删除
	
	//vi.clear() 和 vi.erase(vi.begin(),vi.end());非常相同 
	
	
	
	for(auto it:vi) cout<<it<<" ";
	
	
	return 0;
}
