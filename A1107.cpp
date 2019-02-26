#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1010;

int n,k,h;
int father[maxn];        //���˵���Ⱥ��������˭ 
int isRoot[maxn] = {0};  //������ǲ�����Щ�˵����� 
int course[maxn] = {0};  //���������˭ϲ��
 
//Ҳ����˵��������������ţ�һ�������ˣ�����һ�����ǰ��á�
//�������ڶ������������������˻���  

//course:key ���� value���˵ı��
//isRoot��key�˵ı�� value:�ǲ��Ǹ��ڵ㣬���Ǹ��ڵ������һ������Ⱥ
//father:key �˵ı�� value���˵ı�ţ�����
 
//·��ѹ�� 
int findFather(int x){
	if(x == father[x]){
		return x ;
	} 
	else{
		int X = findFather(father[x]);
		father[x] = X;
		return X;
	}
}
//union�ǹؼ��֣����׳���� 
void Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb){
		father[fa] = fb; 
	}
}
void init(){
	scanf("%d",&n); 
	for(int i= 1 ;i<=n;i++){
		father[i] = i;
		isRoot[i] = false;
	}
	for(int i =1;i<=n;i++){
		//i���ǵ�ǰ���˵ı�� 
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			//h���ǰ��� 
			scanf("%d",&h);
			//�������ĳһ����ϲ����һ�Ѱ���
			//Ϊ0����˵��ǰϲ��������õ��˻�δ֪ 
			if(course[h] == 0){
				//���ָ��ĳ������Ϊh���� 
				//������h��Ȼ������˵ı����i 
				course[h] = i;
			}
			//��һ�ε�union�������壬�����޷�
			//�ڶ��ε�union��ϲ��ĳһ�����õ��ˣ���ϲ��������õ���Ⱥ���кϲ�
			//������ᷢ�֣�һ���˻�ϲ���ܶ�İ��ã�����ôȷ��˵���᲻��ͬʱ���ںü�����Ⱥ
			//���ⲻ����ô���ӡ�����������һ����Ⱥ��ϲ���ü������� 
			Union(i,findFather(course[h]));
		}
	}
}
bool cmp(int a,int b) {
	return a>b; 
} 

int main(){
	init();
	//isRoot�ĳ�ʼ����ֵ����false,����Խ��Խ�� 
	//isRoot��Ϊ0�ĸ����������յ���Ⱥ�ĸ��� 
	//���ѭ�����Ǹ�ֵisRoot���飬��ʽ����true����false������˵������伶�������
	//�����Ƕ����˵İְ֡��������� 
	for(int i= 1 ;i<=n;i++){
		//����ÿһ���ڵ㣬�ҵ����İְ֣�Ȼ�������ְ�+1; 
		isRoot[findFather(i)]++;
	}
	//��ʼͳ�����䵽���м��� 
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(isRoot[i] != 0 ){
			ans++;
		}
	}
	printf("%d\n",ans);
	//�������������ʽ 
	sort(isRoot +1, isRoot+n+1,cmp);
	//�������� 
	for(int i =1;i<= ans;i++){
		printf("%d",isRoot[i]);
		//��ӡÿ����Ⱥ�İ��õ����� 
		if(i <ans) printf(" ");
	}
	return 0;
}
