#include<iostream>
using namespace std;
struct point{
	int x;
	int y;
	//����򻯵Ĺ��캯�� 
	point(int _x,int _y):x(_x),y(_y){};
};
int main() {
	point pts = point(10,20);
	cout<<pts.x<<" "<<pts.y<<endl;
}
