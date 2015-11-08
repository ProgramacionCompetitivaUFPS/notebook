Dado un grafo acíclico y dirigido, ordena los nodos linealmente de tal manera que si existe una arista entre los nodos u y v entonces u aparece antes que v.
Este ordenamiento es una manera de poner todos los nodos en una línea recta de tal manera que las aristas vayan de izquierda a derecha.

int v;
vector<int> topoSort;
vector<int> ady[tam];
int marked[tam];

void init(){
	for (int j = 0; j <= v; j++) {
       marked[j] = 0;
       ady[j].clear();
    }
    topoSort.clear();
}

void dfs(int u){
	int i, v;
	marked[u]==1;
	for(i=0; i<ady[u].size(); i++){
		v=ady[u][i];
		if(marked[v]==0)
			dfs(v);
	}
	topoSort.push_back(u);
}

int main(){
	init();
	int i;
	for(i=0; i<v; i++){
		if(marked[i]==0)
			dfs(i)
	}
	//imprimir topoSort en reversa :3
}

