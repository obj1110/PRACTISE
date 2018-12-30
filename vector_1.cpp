#include<iostream> 
#include<vector>
using namespace std;
vector<int> array;
int main(){
	const int max_size = 0xff;
	for(int i=0;i<max_size;i++){
		array.push_back(i);
	}
	printf("%d\n",array.at(66));
	printf("%d\n",array.front());
	printf("%d\n",array.back());
	
	array.push_back();
	array.pop_back();
	array.insert();//在指定的位置插入或者是删除元素 
	
	array.clear();//全删除 
//	push_back()的效率问题
//	迭代器范围删除是前闭后开[a,b)
	array.erase();//删除一个或者多个指定位置的元素 
	array.erase(array.begin(),array.end());
//	array.begin()是一开始的指针
//	array.end()是最后的结束位置的指针 

//	.front back是具体的元素，而.begin .end是元素的指针 

//	判断作用的语句
	array.empty();//推荐判空 
	array.size();
	
//  动作类的语句 
	array.resize();//改变原有的大小,不扩容 
	array.capacity();//标准的大小
	array.reserve(); //改变标准容量的大小,扩容 
	
//  迭代类的语句
	array.begin();// 
	 
	
	
	return 0;
}
