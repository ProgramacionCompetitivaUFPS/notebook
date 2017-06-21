Algoritmo para hallar los puentes e itsmos en un grafo no dirigido.

vector<int> ady[1010];
int marked[1010];
int previous[1010];
int dfs_low[1010];
int dfs_num[1010];
int itsmos[1010];
int n, e;
int dfsRoot,rootChildren,cont;
vector<pair<int,int>> bridges;

void init(){
    bridges.clear();
    cont=0;
    int i;
    for(i=0; i<n; i++){
        ady[i].clear();
        marked[i]=0;
        previous[i]=-1;
        itsmos[i]=0;
    }
}

void dfs(int u){
    dfs_low[u]=dfs_num[u]=cont;
    cont++;
    marked[u]=1; 
    int j, v;

    for(j=0; j<ady[u].size(); j++){
        v=ady[u][j];
        if(marked[v]==0){
            previous[v]=u;
            //para el caso especial 
            if(u==dfsRoot){
                rootChildren++;
            }
            dfs(v);
            //Itsmos
            if(dfs_low[v]>=dfs_num[u]){
                itsmos[u]=1;
            }
            //Bridges
            if(dfs_low[v]>dfs_num[u]){
                bridges.push_back(make_pair(min(u,v),max(u,v)));
            }
            dfs_low[u]=min(dfs_low[u], dfs_low[v]);
        }else if(v!=previous[u]){ //Arco que no sea backtrack
            dfs_low[u]=min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(){
    //Antes de ejecutar el Algoritmo
    cont=0;
    dfsRoot=0;
    rootChildren=0;
    dfs(0);
}