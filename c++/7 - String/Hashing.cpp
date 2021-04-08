Convierte el string en un polinomio, en O(n), tal que podemos comparar substrings como valores numericos en O(1).
Primero llamar calc_xpow() (una unica vez) con el largo maximo de los strings dados.

inline int add(int a, int b, const int &mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, const int &mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, const int &mod) { return 1ll*a*b % mod; }

const int X[] = {257, 359};
const int MOD[] = {(int)1e9+7, (int)1e9+9};
vector<int> xpow[2];

struct hashing {
    vector<int> h[2];
    
    hashing(string &s) {
        int n = s.size();
        for (int j = 0; j < 2; ++j) {
            h[j].resize(n+1);
            for (int i = 1; i <= n; ++i) {
                h[j][i] = add(mul(h[j][i-1], X[j], MOD[j]), s[i-1], MOD[j]);
            }
        }
    }
    //Hash del substring en el rango [i, j)
    ll value(int l, int r) {
        int a = sbt(h[0][r], mul(h[0][l], xpow[0][r-l], MOD[0]), MOD[0]);
        int b = sbt(h[1][r], mul(h[1][l], xpow[1][r-l], MOD[1]), MOD[1]);
        return (ll(a)<<32) + b;
    }
};

void calc_xpow(int mxlen) {
    for (int j = 0; j < 2; ++j) {
        xpow[j].resize(mxlen+1, 1);
        for (int i = 1; i <= mxlen; ++i) {
            xpow[j][i] = mul(xpow[j][i-1], X[j], MOD[j]);
        }
    }
}