import java.util.*;

class DisjointSet{
	private int [] parent, size;
	private int cantSets;

	//Inicializa todas las estructuras :)
	public DisjointSet(int n){
		parent=new int[n];
		size=new int[n];
		cantSets=n;

		int i;
		for(i=0; i<n; i++){
			parent[i]=i;
			size[i]=1;
		}
	}

	//Operaciones
	public int find(int i){
		parent[i] = ( parent[i] == i ) ? i : find(parent[i]);
    	return parent[i];
	}

	public void union(int i, int j){
		int x=find(i);
		int y=find(j);

		if(x!=y){
			cantSets--;
			parent[x] = y;
		}
	}

	public int numDisjointSets(){
		return cantSets;
	}

	public int sizeOfSet(int i){
		return size[find(i)];
	}
	
}