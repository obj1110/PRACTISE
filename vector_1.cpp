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
	array.insert();//��ָ����λ�ò��������ɾ��Ԫ�� 
	
	array.clear();//ȫɾ�� 
//	push_back()��Ч������
//	��������Χɾ����ǰ�պ�[a,b)
	array.erase();//ɾ��һ�����߶��ָ��λ�õ�Ԫ�� 
	array.erase(array.begin(),array.end());
//	array.begin()��һ��ʼ��ָ��
//	array.end()�����Ľ���λ�õ�ָ�� 

//	.front back�Ǿ����Ԫ�أ���.begin .end��Ԫ�ص�ָ�� 

//	�ж����õ����
	array.empty();//�Ƽ��п� 
	array.size();
	
//  ���������� 
	array.resize();//�ı�ԭ�еĴ�С,������ 
	array.capacity();//��׼�Ĵ�С
	array.reserve(); //�ı��׼�����Ĵ�С,���� 
	
//  ����������
	array.begin();// 
	 
	
	
	return 0;
}
