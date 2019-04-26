Estructura para realizar operaciones de hashing. 

long long p[] = {257, 359};
long long mod[] = {1000000007, 1000000009};
long long X = 1000000010;
 
struct hashing {
    vector<long long> h[2], pot[2];
	int n;
 
    hashing(string s) {
        n = s.size();
        for (int i = 0; i < 2; ++i) {
            h[i].resize(n + 1);
            pot[i].resize(n + 1, 1);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                h[j][i] = (h[j][i - 1] * p[j] + s[i - 1]) % mod[j];
                pot[j][i] = (pot[j][i - 1] * p[j]) % mod[j];
            }
        }
    }
	//Hash del substring en el rango [i, j)
    long long hashValue(int i, int j) {
        long long a = (h[0][j] - (h[0][i] * pot[0][j - i] % mod[0])) % mod[0];
        long long b = (h[1][j] - (h[1][i] * pot[1][j - i] % mod[1])) % mod[1];
        return a*X + b;
    }
};
