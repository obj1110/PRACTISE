#include<iostream>
#include<queue>

using namespace std;

int m,n,l,t,sum;
int G[1288][130][62];
bool inq[1288][130][62] = {false};
//inq���ܡ����Ƿ��Ѿ�����ӣ� 
 
int X[6]={-1,1,0,0,0,0},Y[6]={0,0,-1,1,0,0},Z[6]={0,0,0,0,-1,1};

struct node{
	int x,y,z;
	node(){
		
	}
	node(int _x,int _y,int _z){
		x = _x; y =_y; z =_z;
	}
}Node;

bool check(int x,int y,int z){
	if(x<0||x>=m||y<0||y>=n||z<0||z>=l){
        return 0;
    }
    if(G[x][y][z]==0||inq[x][y][z]==1){
//    	inq[x][y][z]==1;
        return 0;
    }
    return 1;
}

//����ǰ�������е�Ԫ�ض�����Ϊ1 

//
int BFS(int x,int y,int z){
	//�ӿ� 
	int count =0;
	inq[x][y][z] = true;
	node temp,top;
	temp.x = x;temp.y = y;temp.z = z;
	//
	queue<node> q;
	q.push(temp);
//	count++; ��Ҫ����ӣ��涨���ˣ�ֻ�г��ӵ�ʱ��ż� 
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
            	//Ѱ��һ��ȫ�¿��е�ĳ��Ԫ�� 
                if(inq[i][j][k] == false && G[i][j][k] == 1){
                	sum +=BFS(i,j,k);
				}
            }
        }
    }
    printf("%d\n",sum);
	return 0;
}


