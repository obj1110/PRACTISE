#include <iostream>
#include <cstdlib> 
using namespace std;
int main ()
{
  char sentence []="Rudolph is 12 years old";
  char str [20],str1[20],str2[20];
  int i;
  //将字符串进行拆解 
  sscanf (sentence,"%s %s %d",str,str1,&i);
  cout<<str<<" "<<str1<<" " <<i<<endl;
  //重组字符串 
  sprintf(str2,"%s-%s-%d",str,str1,i);
  cout<<str2<<endl;
}
