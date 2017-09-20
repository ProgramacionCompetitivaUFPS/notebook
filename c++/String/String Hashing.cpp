Estructura para realizar operaciones de hashing. 

int p = 265; //Número pseudo-aleatorio base del polinomio (mayor al tamaño del lenguaje)
int MOD = 1000000009; //Número primo grande

struct hashing {
	string s;
	vector<int> h;
	vector<int> pot;
	hashing(string _s) {
		h.resize(_s.size() + 1);
		pot.resize(_s.size() + 1);
		s = _s; h[0] = 0; pot[0] = 1;
		for(int i = 1; i <= s.size(); i++) {
			h[i] = ((long long)h[i - 1] * p + s[i - 1]) % MOD;
			pot[i] = ((long long)pot[i - 1] * p) % MOD;
		}
	}
	int hashValue(int i, int j) {
		int ans = h[j] - (long long) h[i] * pot[j - i] % MOD;
		return (ans >= 0) ? ans : ans + MOD;
	}
};