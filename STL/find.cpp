#include<iostream> 
#include<vector> 
#include<algorithm> 
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
	string str = "1a2b3c4d5e 6f7g8h 9i1a2b3c4d5 e6f7g8ha9i";
	std::size_t position = str.find("5",10);
	if(position != str.npos) cout<<position<<endl;
	std::size_t position2 = str.find("根本不存在"); 
	if(position2 != str.npos) cout<<position2<<endl;
	
	str = "1a2b3c4d5e 6f7g8h 9i1a2b3c4d5 e6f7g8ha9i";
	char str2find[20] = "e 6";
	std::size_t pos= str.find(str2find);
	if(pos != str.npos) cout<<pos<<endl;
	
	str = "1a2b3c4d5e 6f7g8h 9i1a2b3c4d5 e6f7g8ha9i";
	strcpy(str2find,"e6");
	pos= str.find(str2find,0,1);	
	if(pos != str.npos) {
		cout<<"结果为:"<<pos<<endl;	
	}
}
