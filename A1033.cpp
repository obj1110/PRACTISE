#include<iostream>
#include<algorithm>

using namespace std;

struct g{
	float p; // �Ǽ۸� 
	float d;   // �Ǿ��� ��Ҳ�����뺼�ݵľ��� 
}gas[500];
 
bool cmp(g a,g b){
	return a.d < b.d;
}

int main(){
	//d���ܾ��� c����������� davg�ǵ�λ�����ľ���
	//N���ܵļ���վ���� 
	float c,d,davg;
	int n;
	scanf("%f %f %f %d",&c,&d,&davg,&n);
	int i=0;
	for(i=0;i<n;i++){
		scanf("%f %f",&gas[i].p,&gas[i].d);
	}
	//��������һ������վ
	gas[n].p =0.0;
	gas[n].d = d;
	sort(gas,gas+n,cmp);
	//���������Ϊfloat��Ե���޷�cmp...... 
	float max = c*davg;
	float dis=0.0;
	float money =0.0;
	// ���� 
	if(gas[0].d != 0.0){
		printf("The maximum travel distance = %0.2f",dis);
	}
	// i�ǵ�ǰ�ļ���վ 
	int now,next;
	
	for(int i=0;i<n;i++) {
		now = 0;
		next = 1;
		bool flag = false;
		while(flag!=false){
			
			if ((gas[next].d - gas[now].d) > max) {
				dis += max;
				printf("The maximum travel distance = %0.2f",dis);
				return 0;
			}
			else{
				if(gas[next].p <= gas[now].p){
					dis += gas[next].d - gas[now].d;
					money += dis*gas[now].p;
					flag = true;
				}
				else{
					next = next+1;
					if(next==n){
						money += (gas[next].d-gas[now].d)*gas[i].p;
						printf("%0.2f",money);
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
