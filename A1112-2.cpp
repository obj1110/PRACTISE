#include<iostream>
#include<string>
using namespace std;
int main()
{
//	hash值如果是负值就代表是hao的，如果是0就代表huai了 
    int n,i,j;
	int hash[256]={0};
    string s;
    cin>>n>>s;
    int len=s.length();
    for(i=0;i<=len-n;i++){
    	//这种写法非常的精妙啊，属于将while循环和for循环组合的形式 
        for(j=1;j<n&&s[i+j]==s[i];j++);
        //不管你结果如何，我就循环 
		//循环之后，如果j到了n的位置处 
        if(j==n){   //s[i]与后边的n-1个数相同,判断为坏键
            if(hash[s[i]]==0)
                hash[s[i]]=1;
            i+=(n-1);
        }
        else hash[s[i]]=-1; //正常键
    }
    for(i=0;i<len;i++){ //输出坏键
        if(hash[s[i]]==1){
            cout<<s[i];
            hash[s[i]]=2;
        }
    }
    cout<<endl;
    for(i=0;i<len;i++){ //输出原本的字符串
        cout<<s[i];
        if(hash[s[i]]>0)
        	//非常厉害的操作 
            i+=(n-1);
    }
    return 0;
}
