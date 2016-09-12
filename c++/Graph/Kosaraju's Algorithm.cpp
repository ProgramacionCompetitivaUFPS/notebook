Dado un grafo dirigido, calcula la componente fuertemente conexa a la que pertenece cada nodo.

//aka Finding Strongly Connected Components
vector<int> ady[tam];
vector<int> rev[tam];
vector<int> topoSort;
int scc[tam];
int marked[tam];
int n,e; //vertices, arcos

void init(){
	topoSort.clear();
	for(int i=0; i<n; i++){
		ady[i].clear();
		marked[i]=0;
		scc[i]=-1;
		rev[i].clear();
	}
}

void topologicalSort(int u){
	int i, v;
	marked[u]=1;
	for(i=0; i<ady[u].size(); i++){
		v=ady[u][i];
		if(marked[v]==0)
			topologicalSort(v);
	}
	topoSort.push_back(u);
}

void dfs(int u, int comp){
	scc[u]=comp;
	int i, v;
	for(i=0; i<rev[u].size(); i++){
		v=rev[u][i];
		if(scc[v]==-1)
			dfs(v, comp);
	}
}

int findScc(){
	int i, j, v;
	
	//Construye el grafo invertido
	for(i=0; i<n; i++){
		for(j=0; j<ady[i].size(); j++){
			v=ady[i][j];
			rev[v].push_back(i);
		}
	}
	
	//Enumera todos los nodos del grafo original
	for(i=0; i<n; i++){
		if(marked[i]==0)
			topologicalSort(i);
	}

	reverse(topoSort.begin(), topoSort.end());
	
	//dfs, de acuerdo al orden del toposort
	int comp=0;
	for(int i=0; i<n; i++){
		v=topoSort[i];
		if(scc[v]==-1)
			dfs(v, comp++);
	}
	return comp;
}

