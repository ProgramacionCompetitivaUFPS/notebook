//Devuelve el el minimo de los maximos entre pares de rangos consecutivos haciendo cortes en el Array.

static final int MAX = 1005;
static long dp[][] = new long[MAX][MAX];
static long sum_ran[][] = new long [MAX][MAX];
static int N;

static long f(int i, int cuts){
	if(cuts == 0) return sum_ran[i][N-1];
	if(i == N) return 0;
	long ans = dp[i][cuts];
	if(ans != - 1) return ans;
	for(int j = i; j < N; j++){
		ans = Math.min(ans, Math.max(sum_ran[i][j], f(i + 1, cuts - 1)));
	}
	return ans;
}
