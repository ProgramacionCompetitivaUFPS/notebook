//METODO PARA CALCULAR EL LIS en O(n^2) y O(nlog(n)). La ventaja de tener a mano O(n^2) es porque es mas facil de codear, entender y modificar

const int MAX = 1000;

int A[MAX];
int dp[MAX];
int N = MAX;
vector<int> LIS; //PARA Lis_opt
	

//LIS O(n^2).Si es non-decreasing cambiar (i > j) por (i >= j)
int lis(){
	int best = -1;
	for(int i = 0; i < N; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 1);			
		}
		best = max(best, dp[i]);
	}
	return best;
}


//LIS O(nlog(n)) Para longest non-decreasing cambiar lower_bound por upper_bound
int lis_opt(){
	LIS.clear();
	for(int i = 0; i < N; i++){
		auto id = lower_bound(LIS.begin(), LIS.end(), A[i]);
		if(id == LIS.end()) LIS.push_back(A[i]);
		else{
			int idx = id - LIS.begin();
			LIS[idx] = A[i];
		}
	}
	return LIS.size();
}

//Metodo para calcular y además reconstruir el LIS O(nlogn)
int build_lis(){
	LIS.clear();
	int parent[N], last;
	vector<int> rb;
	for(int i = 0; i < N; i++){
		auto id = lower_bound(LIS.begin(), LIS.end(), A[i]);
		if(id == LIS.end()){ 
			LIS.push_back(A[i]);
			rb.push_back(i);
			if(i) parent[i] = rb[rb.size() - 2];
			else parent[i] = -1;
			last = i;
		}
		else{
			int idx = id - LIS.begin();
			LIS[idx] = A[i];
			rb[idx] = i;
			parent[i] = rb[idx - 1]; 
		}
	}
	//Reconstruye el LIS
	vector<int> aux;
	while(last!=-1){
		aux.push_back(A[last]);
		last = parent[last];
	}
	
	for(int i = aux.size() - 1; i >= 0; i--){
		cout << aux[i] <<" ";
	}
	cout << '\n';
	return LIS.size();	
}
