#include<iostream>
#include<algorithm>

using namespace std;

//寻找左边界，左闭右开 
int bs1(int array[],int left,int right,int key){
	int l = left;
	int r = right;
	while(l < r){
		int mid = l + (r - l)/2;
		if(array[mid] <key) l = (mid+1);
		else if(array[mid]<= key) r = mid;
	}
	//最后的结果也许都没找到，包括了最钱买和最后面 
	return array[l]<=key?l:-1;
}
//标准 
int bs(int array[],int key) {
	int left =0;
	int right = array.length -1;
	while(left < right){
		int mid  = left + (right - left)/2; 
		if(array[mid] == key ) return mid;
		else if(array[mid] > key) right = mid-1;
		else left = mid + 1;
	}
	return -1;
}


int main(){
	int arrayOdd[11] = {1,2,3,4,5,6,7,9,10,11,12};
	int arrayEven[10] = {1,2,3,4,5,6,7,9,10,11};
	int index1  = bs1(arrayOdd,0,11,8);
	int index2 = bs1(arrayEven,0,10,8);
	cout<<index1<<endl; 
	cout<<index2<<endl;
	
	vector<int> vodd(arrayOdd,arrayOdd+11);
	vector<int>::iterator it;
	for(it = vodd.begin();it < vodd.end();it++) {
		cout<<*it<<endl;
	}
	int i_temp  = binary_search(vodd.begin(),vodd.end(),8);
	cout<<"vector_result:"<<i_temp<<endl;
	i_temp = binary_search(vodd.begin(),vodd.end(),9);
	cout<<"vector_result:"<<i_temp<<endl;
	//STL自带的binary_search返回的是bool 
	//STL 
	int index3 = binary_search(vodd.begin(),vodd.end(),8);
	cout<<index3<<endl;
	//STL
	//upper_bound 返回的是一个指针 
	int i4 = upper_bound(arrayOdd,arrayOdd+11,8) - arrayOdd;
	int i5 = lower_bound(arrayEven,arrayEven+10,8) - arrayEven; 
	cout<<"i4:"<<i4<<endl;
	cout<<"i5:"<<i5<<endl;
	//自带的binary-search很废，因为只能针对容器vector，而且不能返回位置index  
//	int i6 = binary_search(arrayOdd,11,8);
//	cout<<"i6:"<<i6<<endl;
	return 0;
}
