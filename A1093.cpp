#include<iostream> 
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int maxn = 100100;
const int constNumber = 1000000007;
char array[maxn]={};

int main(){
	cin>>array;
	long long int cts;	
	int length = strlen(array);
	int countP = 0;
	int countT = 0;
	int ans = 0;
	//统计T的个数 
	for(int i=0;i<length;i++){
		if(array[i] == 'T') countT++;
	}
	//统计P的个数
	for(int i=0;i<length;i++){
		if(array[i] == 'P') countP++;
		else if(array[i] == 'T') countT--;
		else if(array[i] == 'A'){
			ans = (ans + countP*countT)%constNumber; 
		}
	}
	cout<<ans<<endl; 
	return 0;
}
