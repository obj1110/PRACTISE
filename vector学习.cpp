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
	//���ֶ�ά���� 
	vector<int> ve[100]; //��ά���ɱ� 
	vector<vector<int>> name; //ֻ��һ��ά�ȿ��Ըı�
	
	int size  = 10;
	int value  = 5 ;
	vector<int> vi(size,value);
	for(int i =1;i<=3 ;i++) {
		vi.push_back(i);
	}
	
	
	vi.pop_back();
	vi.insert(vi.begin()+2,-1);
	vi.insert(vi.begin()+2,-5);
	
	vi.erase(vi.begin() +9); //ɾ������vi[9]��Ԫ�أ���Ϊvi.begin�����Ӧ����vi[0] 
	vi.erase(vi.begin()+1,vi.begin()+3); //��Χɾ��
	
	//vi.clear() �� vi.erase(vi.begin(),vi.end());�ǳ���ͬ 
	
	
	
	for(auto it:vi) cout<<it<<" ";
	
	
	return 0;
}
