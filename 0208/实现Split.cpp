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

//��Ҫ��˼·������substr�� find���ϵĽ��б�����ָ��ʵ������Ҳ�������ĸ�Ĵ��� 
vector<string> Split(string str, string c){ 
	vector<string> v;
	//size_type��ȫ�ֵģ�size_t��������ص� 
	string::size_type pos1,pos2;
	//find���صĲ��ǵ���������һ��ָ�� 
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

//�ǲ��Ǹо��ǲ�ס�����Ķ�������
//���Ի��ǰ�����ĸ����if elseѭ������ò������ˡ�
//����һ�� ��ʱ��string temp������ int cts������¼���� ��������ò������� 

int main(){
	
}
