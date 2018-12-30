#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
//四个迭代器 
//vec.begin()
//vec.end()
//vec.rbegin() 
//vec.rend()

vector<int> array;
int main(){
	const int max_size = 0xff;
	for(int i=0;i<max_size;i++){
		array.push_back(i);
	}
	vector<int>::iterator ite_1;
	for(ite_1 = array.begin();ite_1 != array.end();ite_1++) {
		cout<<*ite_1<<endl;
	}
	
	vector <int> array2(100,0);
	vector<int>::iterator ite_2;
	for(ite_2 = array2.begin();ite_2 != array2.end();ite_2++){
		cout<<*ite_2<<endl;
	}
	
//	vector<int> array3(100,1);
//	vector<int>::iterator ite_3 = array3.r;
//	for(ite_3 = array3.rbegin();ite_3 != array3.rend();ite_3++){
//		cout << *ite_3<<endl;
//	}
	
// 初始化
vector<int> v(10,0);
vector<int> v2(v.begin(),v.end());
int array[10];
//数组复制操作 
v2.assign(10,0);
v2.assign(v.begin(),v.end());
v2.assign(v.begin(),v.begin()+5);
v2.assign(array,array+5);
//可以接受一个数组的元素的传递,也可以接收一个数组的指针的传递 
 
	return 0;
}
