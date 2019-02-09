#include<string>
#include<iostream>

using namespace std;

void Split(string str, vector<string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

//主要的思路，依靠substr和 find不断的进行遍历后分割，其实本质上也是逐个字母的处理 
vector<string> Split(string str, string c){ 
	vector<string> v;
	//size_type是全局的，size_t是容器相关的 
	string::size_type pos1,pos2;
	//find返回的不是迭代器而是一个指针 
	pos2 = s.find(c);
	pos1 = 0;
	while(string::npos != pos2) {
		v.push_back(str.substr(pos1,pos2-pos1));
		pos1 = pos2 + c.size() ;
		pos2 = str.find(c,pos1);
	}
	if(pos1 != s.length()){
		v.push_back(s.substr(pos1)) ;
	}
}

//是不是感觉记不住上述的东西？？
//所以还是按照字母处理，if else循环是最好不过的了。
//创建一个 临时的string temp变量和 int cts变量记录长度 ，都是最好不过的了 

int main(){
	
}
