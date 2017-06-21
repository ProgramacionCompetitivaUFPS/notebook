Algoritmo para hallar los puentes e itsmos en un grafo no dirigido. Requiere de la clase Edge.

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

/* Recibe el nodo inicial */
static void dfs(int u){
    dfs_low[u] = dfs_num[u] = cont;
    cont++;
    marked[u] = true;
    int j, v;

    for(j = 0; j < ady[u].size(); j++){
        v = ady[u].get(j);
        if( !marked[v] ){
            prev[v] = u;
            //Caso especial 
            if( u == dfsRoot )  rootChildren++;
            dfs(v);

            //Itmos
            if( dfs_low[v] >= dfs_num[u] )  itsmos[u]=1;
            
            //Puentes
            if( dfs_low[v] > dfs_num[u] )   bridges.add(new Edge( Math.min(u,v),Math.max(u,v)) );
            
            dfs_low[u] = Math.min(dfs_low[u], dfs_low[v]);
        }else if( v != prev[u] )    dfs_low[u] = Math.min(dfs_low[u], dfs_num[v]);
    }
}

public static void main(String args[]){
    //Antes de ejecutar el Algoritmo
    cont = dfsRoot = rootChildren = 0;
    bridges = new ArrayList<Edge>();
    dfs( dfsRoot );
    /* Caso especial */
    itmos[dfsRoot] = ( itmos[ dfsRoot ] == 1 && rootChildren > 1 ) ? 1 : 0;
}

