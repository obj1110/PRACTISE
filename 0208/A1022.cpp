//建立若干map，建立关键词到图书ID的映射；
//用set保存，所有ID自然增序排列；
//按题目要求输出结果，并返回0值。


//nandian: 数据结构，处理输入的问题
 
#include<iostream> 
#include<map> 
#include<cstdlib>
#include<set> 

using namespace std;

//一步到位的数据结构，非常厉害 
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
	//temp是等待索引的字符串 
	string title,author,key,year,pub,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&id);
		//什么情况下需要使用getchar  
		//在scanf后面的getchar主要是用于吸收换行符号 
		char c = getchar();
		//getline用于读取带有空格的东西 
		
        getline(cin,title);//读入书名title 
        mptit[title].insert(id);//把id加入title对应的集合中 
        getline(cin,author);//读入作者author 
        mpaut[author].insert(id);//把id加入author对应的集合中 
        
        //不是针对整个索引建立一个keywords的map，而是针对每一个单次建立一个words的map 
        while(cin>>key){//每次读入单个关键词key 
            mpkey[key].insert(id);//把id加入key对应的集合中 
            c=getchar();//接收关键词key之后的字符 ，主要是吸收空格 
            if(c=='\n'){//如果是换行，说明关键词输入结束 
                break;
            }
        }
        
        getline(cin,pub);//输入出版社pub 
        mppuber[pub].insert(id);//把id加入pub对应的集合中 
        getline(cin,year);//输入年份year 
        mppubyr[year].insert(id);//把id加入year对应的集合中 
	}
	
	scanf("%d",&m);//查询次数
    for(int i=0;i<m;i++){
    	//这里有一个细节就是把：进行了省略读取 
        scanf("%d: ",&type);//查询类型 
        getline(cin,temp);//欲查询的字符串 
        cout<<type<<": "<<temp<<endl;//输出类型和该字符串 
        if(type == 1){
            query(mptit,temp);//查询书名对应的所有id
        }else if(type == 2){
            query(mpaut,temp);//查询作者对应的所有id
        }else if(type==3){
            query(mpkey,temp);//查询关键词对应的所有id
        }else if(type==4){
            query(mppuber,temp);//查询出版社对应的所有id
        }else{
            query(mppubyr,temp);//查询出版年份对应的所有id
        }
	} 
	return 0;
}
