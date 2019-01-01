#include<iostream>
#include<vector>
#include<cstring> 
#include<algorithm>
using namespace std;

char index[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'}; 
int main(){
	char temp[110];
	scanf("%s",temp);
	vector<char> str1(begin(temp),end(temp)); 
	scanf("%s",temp);
	vector<char> str2(begin(temp),end(temp)); 

	for(vector<char>::iterator ite = str1.begin(); ite != str1.end();ite++){
		cout<<*ite;
	}
	cout<<endl<<"-------------"<<endl;
	for(vector<char>::iterator ite = str2.begin(); ite != str2.end();ite++){
		cout<<*ite;
	}
	
	reverse(str1.begin(),str1.end());
	reverse(str2.begin(),str2.end());
	
	
	
//	int i=1;
//	int j=1;
//	while(i<=sizeof(str1)/sizeof(str1[0]) && j<=sizeof(str2)/sizeof(str2[0])){
//		if(i%2==1){
//			str1[i-1] = index[(str1[i-1] + str2[i-1])%13];
//		}
//		else if(i%2==0){
//			str1[i-1] = (str2[i-1] - str1[i-1])>=0?(str2[i-1]-str1[i-1]+'0'):(str2[i-1]-str1[i-1]+10+'0'); 
//		}
//		i++;
//		j++;
//	}
//	for(int i=0;i<(sizeof(str1)/sizeof(str1[0]));i++){
//		cout<<str1[i];
//	}
}
