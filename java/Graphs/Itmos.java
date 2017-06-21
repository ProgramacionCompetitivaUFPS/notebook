Algoritmo para hallar componentes fuertemente conexas(SCC) en grafos dirigidos.

import java.util.ArrayList;
import java.lang.Math;


static int n, e; //vertices, arcos
static int MAX=1010;     
static ArrayList<Integer> ady[]=new ArrayList [MAX];
static boolean marked[]=new boolean [MAX];
static int prev[]=new int [MAX];
static int dfs_low[]=new int [MAX];
static int dfs_num[]=new int [MAX];
static int itsmos[]=new int [MAX];
static ArrayList<Edge> bridges;
static int dfsRoot, rootChildren, cont;

static void init() {
    bridges=new ArrayList<Edge>();
    cont=0;
    int i;
    for(i=0; i<n; i++){
        ady[i]=new ArrayList<Integer>();
        marked[i]=false;
        prev[i]=-1;
        itsmos[i]=0;
    }
}

static void dfs(int u){
    dfs_low[u]=cont;
    dfs_num[u]=cont;
    cont++;
    marked[u]=true;
    int j, v;

    for(j=0; j<ady[u].size(); j++){
        v=ady[u].get(j);
        if(!marked[v]){
            prev[v]=u;
            //Caso especial 
            if(u==dfsRoot){
                rootChildren++;
            }
            dfs(v);
            //PARA ITSMOS
            if(dfs_low[v]>=dfs_num[u]){
                itsmos[u]=1;
            }
            //PARA PUENTES
            if(dfs_low[v]>dfs_num[u]){
                bridges.add(new Edge(Math.min(u,v),Math.max(u,v)));
            }
            dfs_low[u]=Math.min(dfs_low[u], dfs_low[v]);
        }else if(v!=prev[u]){ //Arco que no sea backtrack
            dfs_low[u]=Math.min(dfs_low[u], dfs_num[v]);
        }
    }
}

static class Edge{

    public int src, dest;
    
    public Edge(int s, int d) {
        this.src = s;
        this.dest = d;
    }
}

