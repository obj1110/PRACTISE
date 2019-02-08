//用map容器建立字符串到数字的对应关系，用二维数组建立数字到字符串的对应关系

#include<iostream>
#include<map>
#include<utility>
#include<string>
#include<cstring>
#include<cstdlib>

//Zero on Earth is called "tret" on Mars.
//The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars
//For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
using namespace std;

string one[13]  = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string dec_[13] = {"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
//这个十位上的第一个元素用""来代替是非常精妙的 

//map定义错了，实际上应该是由string转int这样的，key是string，value是int 
//为什么用map，就是因为string映射到int没法用数组实现，用结构体实现太麻烦
//map就是类型和类型间的映射关系的建立者 

//Zero on Earth is called "tret" on Mars.
//由于0是4位的所以就很麻烦了
 
map<string,int> mpf;

void Init(){
	mpf["tret"] = 0;
	mpf["jan"] = 1;
	mpf["feb"] = 2;
	mpf["mar"] = 3;
	mpf["apr"] = 4;
	mpf["may"] = 5;
	mpf["jun"] = 6;
	mpf["jly"] = 7;
	mpf["aug"] = 8;
	mpf["sep"] = 9;
	mpf["oct"] = 10;
	mpf["nov"] = 11;
	mpf["dec"] = 12;
	mpf["tret"] = 0;
	mpf["tam"] = 13;
	mpf["hel"] = 26;
	mpf["maa"] = 39;
	mpf["huh"] = 52;
	mpf["tou"] = 65;
	mpf["kes"] = 78;
	mpf["hei"] = 91;
	mpf["elo"] = 104;
	mpf["syy"] = 117;
	mpf["lok"] = 130;
	mpf["mer"] = 143;
	mpf["jou"] = 156;
//	mpf[0] = "tret";
//	mpf[1] = "jan";
//	mpf[2] = "feb";
//	mpf[3] = "mar";
//	mpf[4] = "apr";
//	mpf[5] = "may";
//	mpf[6] = "jun";
//	mpf[7] = "jly";
//	mpf[8] = "aug";
//	mpf[9] = "sep";
//	mpf[10] = "oct";
//	mpf[11] = "nov";
//	mpf[12] = "dec";
//	mpf[13] = "tret";
//	mpf[26] = "tam";
//	mpf[39] = "hel";
//	mpf[52] = "maa";
//	mpf[65] = "huh";
//	mpf[78] = "tou";
//	mpf[91] = "kes";
//	mpf[104] = "hei";
//	mpf[117] = "elo";
//	mpf[130] = "syy";
//	mpf[143] = "lok";
//	mpf[156] = "mer";
//	mpf[169] = "jou";
	//For the next higher digit, the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
}

int StringToNumber(string str) {
	int length = str.size();
	int value = 0;
	if(length == 7){
		string substr = str.substr(0,3);
		value +=  mpf[substr];
		substr = str.substr(4,3);
		value += mpf[substr];
	}
	else if(length == 3){
		string substr = str.substr(0,3);
		value += mpf[substr];
	}
	else if(length == 4 || length ==9){
		value = 0;
	}
	else if(length == 8 ){
		string substr = str.substr(0,3);
		value += mpf[substr];
	}
	return value;
}

string NumberToString(int num){
	if(num ==0){
		return "tret";
	}
	
	string str = dec_[num/13];
	if(num%13 != 0 && str != "") {
		if(str != "") str+= " ";
		str += one[num%13];
		return str;
	}
	else if(str == ""){
		str += one[num%13];
		return str;
	}
	else if(num%13 == 0){
		return str;
	}
	//
	return str;
}


int main(){
	Init();
	int n;
	cin>>n;
	//
	getchar();
	//
	if(n==0){
		return 0;
	}
	while(n--) {
		//用第一位元素是不是数字来判断是不是数字 
		string str;
		//单纯用 cin会严重受到空格的影响，转而用getline，只受到长度或者是 换行的影响 
//		std::cin.getline(str,256);
		getline(cin,str);
		
		//防止错误的输入导致的影响 
		while(!str.empty() && str[0] ==' '){
			str.erase(str.begin());
		}
	
		if(str[0] >= '0' && str[0] <='9'){
			cout<<NumberToString(stoi(str))<<endl;
		}
		else{
			cout<<StringToNumber(str)<<endl;
		}
	}
	return 0;
}
