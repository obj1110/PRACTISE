#include<iostream> 
#include<vector>
using namespace std;
class Solution{
	public:
		//在一个二维数组中来寻找指定的元素 
		bool Find(vector<vector<int>> array ,int target){
			int row = 0 ,col = 0 ,t=0 ;
			bool isFound = false;
			for(int i=0;i<array.size();i++) {
				for(int j=;j<array[i].size();j++){
					if(isFound==false && target==array[i][j]){
						isFound = true;
					}
				}
			}
			return isFound;
		}
};

int main(){
	
}
