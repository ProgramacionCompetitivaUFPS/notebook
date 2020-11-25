const int MAXN=1e5, alpha=26;
const char L = 'A';
int aut[MAXN+2][alpha];	//aut[i][j] = a donde vuelvo si estoy en i y pongo una j
 
void build(string &s){
	int lps=0;
	aut[0][s[0]-L] = 1;
    int n = s.size();
	for(int i = 1; i < n+1; i++){
		for(int j = 0; j < alpha; j++) aut[i][j] = aut[lps][j];
		if(i < n){
			aut[i][s[i]-L] = i+1;
			lps = aut[lps][s[i]-L];
		}
	}
}