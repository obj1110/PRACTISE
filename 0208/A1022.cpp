//��������map�������ؼ��ʵ�ͼ��ID��ӳ�䣻
//��set���棬����ID��Ȼ�������У�
//����ĿҪ����������������0ֵ��


//nandian: ���ݽṹ���������������
 
#include<iostream> 
#include<map> 
#include<cstdlib>
#include<set> 

using namespace std;

//һ����λ�����ݽṹ���ǳ����� 
map<string,set<int>> mptit,mpaut,mpkey,mppuber,mppubyr;

void query(map<string,set<int>> mp,string str) {
	if(mp.find(str) == mp.end() ){
		printf("Not Found\n");
	}
	else{
		for(auto it = mp[str].begin();it != mp[str].end();it++ ){
			printf("%07d\n",*it);
		}
	}
}

int main(){
	int n,id,m,type;
	//temp�ǵȴ��������ַ��� 
	string title,author,key,year,pub,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&id);
		//ʲô�������Ҫʹ��getchar  
		//��scanf�����getchar��Ҫ���������ջ��з��� 
		char c = getchar();
		//getline���ڶ�ȡ���пո�Ķ��� 
		
        getline(cin,title);//��������title 
        mptit[title].insert(id);//��id����title��Ӧ�ļ����� 
        getline(cin,author);//��������author 
        mpaut[author].insert(id);//��id����author��Ӧ�ļ����� 
        
        //�������������������һ��keywords��map���������ÿһ�����ν���һ��words��map 
        while(cin>>key){//ÿ�ζ��뵥���ؼ���key 
            mpkey[key].insert(id);//��id����key��Ӧ�ļ����� 
            c=getchar();//���չؼ���key֮����ַ� ����Ҫ�����տո� 
            if(c=='\n'){//����ǻ��У�˵���ؼ���������� 
                break;
            }
        }
        
        getline(cin,pub);//���������pub 
        mppuber[pub].insert(id);//��id����pub��Ӧ�ļ����� 
        getline(cin,year);//�������year 
        mppubyr[year].insert(id);//��id����year��Ӧ�ļ����� 
	}
	
	scanf("%d",&m);//��ѯ����
    for(int i=0;i<m;i++){
    	//������һ��ϸ�ھ��ǰѣ�������ʡ�Զ�ȡ 
        scanf("%d: ",&type);//��ѯ���� 
        getline(cin,temp);//����ѯ���ַ��� 
        cout<<type<<": "<<temp<<endl;//������ͺ͸��ַ��� 
        if(type == 1){
            query(mptit,temp);//��ѯ������Ӧ������id
        }else if(type == 2){
            query(mpaut,temp);//��ѯ���߶�Ӧ������id
        }else if(type==3){
            query(mpkey,temp);//��ѯ�ؼ��ʶ�Ӧ������id
        }else if(type==4){
            query(mppuber,temp);//��ѯ�������Ӧ������id
        }else{
            query(mppubyr,temp);//��ѯ������ݶ�Ӧ������id
        }
	} 
	return 0;
}
