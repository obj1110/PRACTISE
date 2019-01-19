#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

int binarySearch(char N2[],ll left,ll right,ll t){
	ll mid;
	while(left < right){
		mid  = (left + right)/2;
		int flag = cmp(N2,mid,t);
		if(flag ==0 ) return mid ;
		else if(flag == -1) left = mid+1;
		else if(flag == 1) right = mid -1;
	}
}
