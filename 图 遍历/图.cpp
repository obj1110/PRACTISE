#include<iostream>

//���й�����ȱ��� 
BFS(u){
	queue q;
	inq[q] = true;
	while(!q.empty()){
		top = q.front();
		for(int i=0;i<adj[u].size();i++){
			//Ҳ����û�б���������� 
			if(inq[adj[u][i]] == false){
				//���
				inq[adj[u][i]]  = true;
			}
		}
	}
}

//��ͼ���й�����ȱ��� 
BFSTraverse(G){
	for(G�е����еĽ��) {
		if(inq[v] == false){
			v���
			inq[v]  = true;
		}
	}
}
