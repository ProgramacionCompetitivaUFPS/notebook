Estructura para realizar operaciones de hashing. 

#define mod(a, b) (((a)%(b)+(b))%(b))

ll p[] = {153, 255};
ll MOD[] = {1000000007, 1000000009};
ll X = 1e9 + 10;

struct hashing {
    int n;
    vector<ll> h[2], pot[2];

    hashing(string s) {
        n = s.size();
        for (int i = 0; i < 2; ++i) {
            h[i].resize(n + 1);
            pot[i].resize(n + 1, 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; ++j) {
                h[j][i] = (h[j][i - 1] * p[j] + s[i - 1]) % MOD[j];
                pot[j][i] = (pot[j][i - 1] * p[j]) % MOD[j];
            }
        }
    }

    ll hashValue(int i, int j) {
        ll a = mod(h[0][j] - mod(h[0][i] * pot[0][j - i], MOD[0]), MOD[0]);
        ll b = mod(h[1][j] - mod(h[1][i] * pot[1][j - i], MOD[1]), MOD[1]);
        return a*X + b;
    }
};
