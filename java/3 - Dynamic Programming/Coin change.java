static final int MAX_COINS = 1005;
static final int MAX_VALUE = 1005;
static final int INF = (int) (2e9);
static int coins[] = new int[MAX_COINS];
static int dp[] = new int[MAX_VALUE];
static ArrayList<Integer> rb = new ArrayList<>(); 

//Calcula el número de formas para valores entre 1 y value. SIN CONTAR PERMUTACIONES
static void ways(int value){
	dp = new int[MAX_VALUE];
	dp[0] = 1;
	for(int c: coins){
		for(int i = 1; i <= value; i++){
			if(i - c >= 0) dp[i] += dp[i - c];
		}
	}
}

//Calcula el número de formas para valores entre 1 y value. CONTANDO PERMUTACIONES
static void ways_perm(int value){
	dp = new int[MAX_VALUE];
	dp[0] = 1;
	for(int i = 1; i <= value; i++){
		for(int c: coins){
			if(i - c >= 0) dp[i] += dp[i - c];
		}	
	}
}

//Calcula el minimo numero de monedas necesarias para los valores entre 1 y value.
static void min_coin(int value){
	dp = new int[MAX_VALUE];
	for(int i = 1; i <= value; i++){
		dp[i] = INF;
		for(int c: coins){
			if(i - c >= 0) dp[i] = Math.min(dp[i], dp[i - c] + 1);
		}
	}
}

//Guarda en el vector rb las monedas usadas en min_coin. 
static void build_ways(int value){
	rb.clear();
	for(int c = MAX_COINS - 1; c >= 0; c--){
		if(value == 0) return;
		while(value - coins[c]>= 0 && dp[value] == dp[value - coins[c]] + 1){
			rb.add(coins[c]);
			value -= coins[c];
		}
	}
}
