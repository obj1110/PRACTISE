#include<iostream>
#include<cstring>

using namespace std;
//���������ǳ�ֵ��ѧϰ 
struct person{
  char name[6];
  int yy,mm,dd;
}temp, ans_elder, ans_young, left_bou, right_bou;

//ע�����ұ߽綼�ǿ���ȡ�Ⱥŵġ� 

//�ж�a�ǲ���С��b��Ҳ�����ұ߽��ж�
int Less(person a,person b){
	if(a.yy!=b.yy) return a.yy <= b.yy;
	else if(a.mm!=b.yy) return a.mm <= b.mm;
	else return a.dd <= b.dd;
		//ע�����һ��ֻҪֱ���жϾ��У�ǧ��Ҫ����˼ά����һ����������:
//	else if(a.dd != b.dd)  ����Ǵ���ش����� 
	
}
//Ҳ������߽��ж� Ҳ���������жϳ��ߺ������� 
int More(person a,person b){
	if(a.yy!=b.yy) return a.yy >= b.yy;
	else if(a.mm!=b.yy) return a.mm >= b.mm;
	else return a.dd >= b.dd;
	//ע�����һ��ֻҪֱ���жϾ��У�ǧ��Ҫ����˼ά����һ����������:
//	else if(a.dd != b.dd)  ����Ǵ���ش����� 
} 
void init(){
	ans_young.yy = right_bou.yy = 2014;
	ans_elder.mm = ans_young.mm = right_bou.mm = 9;
	ans_elder.dd = ans_young.dd = right_bou.dd = 6;
	ans_elder.yy = left_bou.yy = 1814;	
} 

int main(){
  init();
  int num,a,b,c,cts = 0 ;
  scanf("%d",&num);
  for(int i=0;i<num;i++){
  	//ע���ַ�����scanf��ʽ 
    scanf("%s %d/%d/%d",temp.name,&temp.yy,&temp.mm,&temp.dd);
    //�жϲ��������ǲ��ǺϷ��� ��С��2014,9,6 
    if(More(temp,left_bou) && Less(temp,right_bou)){
    	cts++;
    	if(More(temp,ans_elder)) ans_elder = temp ;
    	if(Less(temp,ans_young)) ans_young = temp ;
	}
    // �ж������ǲ��ǺϷ��ģ�С��200�꣬Ҳ����2014-9-6 - ���� С��200��
  }
  if(cts == 0) printf("0");
  else printf("%d %s %s",cts,ans_elder.name,ans_young.name);
  return 0;
}
