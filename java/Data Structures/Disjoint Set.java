import java.util.*;

class DisjointSet{
	private int [] parent, rank, size;
	private int cantSets;

	//Inicializa todas las estructuras :)
	public DisjointSet(int n){
		parent=new int[n];
		rank=new int[n];
		size=new int[n];
		cantSets=n;

		int i;
		for(i=0; i<n; i++){
			parent[i]=i;
			rank[i]=0; //Se usa para tener un control sobre el "tamaño" del arbol
			size[i]=1;
		}
	}

	//Operaciones
	public int find(int i){
		if(parent[i]==i)	return i;
		else{
			int x=find(parent[i]);
			//Compresión de ruta
			parent[i]=x;
			return x;
		}
	}

	public void union(int i, int j){
		int x=find(i);
		int y=find(j);

		if(x!=y){
			cantSets--;

			//El set más pequeño (rank) se añade al set más grande
			if(rank[x]>rank[y]){
				parent[y]=x;
				size[x]=size[x]+size[y];
			}else{
				parent[x]=y;
				size[y]=size[y]+size[x];

				if(rank[x]==rank[y]){
					rank[y]=rank[y]+1;
				}
			}

		}
	}

	public int numDisjointSets(){
		return cantSets;
	}

	public int sizeOfSet(int i){
		return size[find(i)];
	}
}