#include<iostream>
#include<queue>

using namespace std;

int m,n,l,t,sum;
int G[1288][130][62];
bool inq[1288][130][62] = {false};
//inq功能——只要曾经用check过，就true
//极大地扩大了inq的功能 
//但是其实跟有没有入过队差不多啊 

//所以说不如认为就是有没有入过队 
 
int X[6]={-1,1,0,0,0,0},Y[6]={0,0,-1,1,0,0},Z[6]={0,0,0,0,-1,1};

struct node{
	int x,y,z;
	node(){
		
	}
	node(int _x,int _y,int _z){
		x = _x; y =_y; z =_z;
	}
}Node;

//check的意义——是不是联通，如果联通，之前有没有便利过 
bool check(int x,int y,int z){
	if(x<0||x>=m||y<0||y>=n||z<0||z>=l){
        return 0;
    }
    if(G[x][y][z]==0||inq[x][y][z]==1){
    	inq[x][y][z] = 1;
        return 0;
    }
    inq[x][y][z] = 1;
    return 1;
}

//将当前块中所有的元素都设置为1 

//
int BFS(int x,int y,int z){
	//子块 
	int count =0;
	inq[x][y][z] = 1;
	node temp,top;
	temp.x = x;temp.y = y;temp.z = z;
	//
	queue<node> q;
	q.push(temp);
//	count++; 不要随意加，规定好了，只有出队的时候才加 
	//
	while(!q.empty()){
		top = q.front();
		q.pop();
		count++;
		//
		for(int dir =0;dir<6;dir++){
			int newx = top.x + X[dir];
			int newy = top.y + Y[dir];
			int newz = top.z + Z[dir];
			if(check(newx,newy,newz)){
				temp.x = newx;temp.y = newy;temp.z =newz;
				q.push(temp);
				inq[newx][newy][newz] = true;
			}
		}
	}
	if(count>=t) return count;
	return 0;
}

int main(){
	scanf("%d %d %d %d",&m,&n,&l,&t);
	for(int k =0 ;k<l;k++){
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++){
				scanf("%d",&G[i][j][k]);
			}
		}
	}
	
	for(int k=0;k<l;k++){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            	//寻找一个全新块中的某个元素 
                if(inq[i][j][k] == false && G[i][j][k] == 1){
                	sum +=BFS(i,j,k);
				}
            }
        }
    }
    printf("%d\n",sum);
	return 0;
}


