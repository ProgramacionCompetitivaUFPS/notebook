Algoritmo para hallar componentes fuertemente conexas(SCC) en grafos dirigidos.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

static int v;
static int n = 5000; // Máxima cantidad de nodos
static int dfs_low[] = new int[n];
static int dfs_num[] = new int[n];
static boolean marked[] = new boolean[n];
static Stack<Integer> s;
static int dfsCont, cantSCC;
static ArrayList<Integer> ady[] = new ArrayList[n];
	
public static void tarjanSCC( int u ){
	dfs_low[u] = dfs_num[u] = dfsCont;
	dfsCont++;
	s.push(u);
	marked[u] = true;		
	int j, v;		
	for( j = 0; j < ady[u].size(); j++ ){
		v = ady[u].get( j );
			
		if( dfs_num[v] == -1 ){
			tarjanSCC( v );
		}
			
		if( marked[v] ){
			dfs_low[u] = Math.min( dfs_low[u], dfs_low[v] );
		}
	}
		
	if( dfs_low[u] == dfs_num[u] ){
		cantSCC++;	
        /* Esta seccion comentada se usa para imprimir las componentes conexas */		
		/* System.out.println("COMPONENTE CONEXA #" + cantSCC );
		while( !s.empty() ){
			v = s.peek();
			s.pop();
			marked[v] = false;
			System.out.println(v);
			if( u == v ) break;
		} */
	}
}

	
public static void main (String[] args){
	
	 for (int i = 0; i <n; i++) { //inicializa las estructuras necesarias para la ejecucion del algoritmo.
                ady[i] = new ArrayList<Integer>();
                dfs_low[i] = 0;
                dfs_num[i] = -1;
		 marked[i] = false;
            }
	
    	for( int i = 0; i < v; i++ ){ //Por si el grafo no es conexo
        if( dfs_num[i] == -1 ){
            dfsCont = 0;
            s = new Stack<Integer>();
            tarjanSCC(i);
        }
    }
}



