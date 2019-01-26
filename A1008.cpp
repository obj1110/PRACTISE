#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int up =6;
const int down =4;
const int stay = 5;

int main(){
	int n;
	int destination;
	int current = 0;
	int ans =0;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	  scanf("%d",&destination);
	  if(destination> current){
	    ans += (destination - current)*up + stay;
	    current = destination;
	  } 
	  else if(destination < current){
	    ans += (destination - current)*down + stay;
	    current = destination;
	  }
	  else{
	    ans += stay;
	    current = destination;
	  }
	}
	cout<<ans;
	return 0;
}


