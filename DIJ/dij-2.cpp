void DFS(int start,int end){
	if(end == start){
		temp.push_back(end);
		//ѡȡ���Ž⣬���Ҽ���õ����Ž� 
		temp.pop_back();
		return;
	}
	else if(end != start) {
		temp.push_back(end);
		for(int i=0;i<pre[end].size();i++){
			DFS(start,pre[end][i]);
		}
		temp.pop_back();
	}
}
