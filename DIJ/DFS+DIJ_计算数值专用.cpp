int optvalue;
vector<int> pre[maxn];
vector<int> path,temppath;
void DFS(int v){
	if(v == st){
		temppath.push_back(v);
		int value;
		for(int i= temppath.size()-1;i>0;i--){
			int id = temppath[i];
			value +=  w[id];
		}
		if(value > optvalue){
			optvalue = value;
			path = temppath;
		}
		temppath.pop_back(); 
		return;
	}
	else{
		temppath.push_back(v);
		for(int i=0;i<pre[v].size();i++){
			DFS(pre[v][i]);
		}
		temppath.pop_back();
	}
}
