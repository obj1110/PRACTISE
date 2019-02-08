//��map���������ַ��������ֵĶ�Ӧ��ϵ���ö�ά���齨�����ֵ��ַ����Ķ�Ӧ��ϵ

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
//���ʮλ�ϵĵ�һ��Ԫ����""�������Ƿǳ������ 

//map������ˣ�ʵ����Ӧ������stringתint�����ģ�key��string��value��int 
//Ϊʲô��map��������Ϊstringӳ�䵽intû��������ʵ�֣��ýṹ��ʵ��̫�鷳
//map�������ͺ����ͼ��ӳ���ϵ�Ľ����� 
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
	mpf["tret"] = 13;
	mpf["tam"] = 26;
	mpf["hel"] = 39;
	mpf["maa"] = 52;
	mpf["huh"] = 65;
	mpf["tou"] = 78;
	mpf["kes"] = 91;
	mpf["hei"] = 104;
	mpf["elo"] = 117;
	mpf["syy"] = 130;
	mpf["lok"] = 143;
	mpf["mer"] = 156;
	mpf["jou"] = 169;
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
	if(length > 4){
		string substr = str.substr(0,3);
		value +=  mpf[substr];
		substr = str.substr(4,3);
		value += mpf[substr];
	}
	else{
		string substr = str.substr(0,3);
		value += mpf[substr];
	}
	return value;
}

string NumberToString(int num){
	string str = dec_[num/13];
	if(str != "") str+= " ";
	str += one[num%13];
	return str;
}


int main(){
	Init();
	int n;
	cin>>n;
	//
	getchar();
	
	while(n--) {
		//�õ�һλԪ���ǲ����������ж��ǲ������� 
		string str;
		//������ cin�������ܵ��ո��Ӱ�죬ת����getline��ֻ�ܵ����Ȼ����� ���е�Ӱ�� 
//		std::cin.getline(str,256);
		getline(cin,str);
		
		//��ֹ��������뵼�µ�Ӱ�� 
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
