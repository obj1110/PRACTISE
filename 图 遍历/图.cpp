#include<iostream>

//进行广度优先遍历 
BFS(u){
	queue q;
	inq[q] = true;
	while(!q.empty()){
		top = q.front();
		for(int i=0;i<adj[u].size();i++){
			//也就是没有遍历过这个点 
			if(inq[adj[u][i]] == false){
				//入队
				inq[adj[u][i]]  = true;
			}
		}
	}
}

//对图进行广度优先遍历 
BFSTraverse(G){
	for(G中的所有的结点) {
		if(inq[v] == false){
			v入队
			inq[v]  = true;
		}
	}
}
