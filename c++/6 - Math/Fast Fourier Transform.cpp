Multiplicación de polinomios en O(n log n)

typedef complex<double> pt;
const double PI = acos(-1.0);

namespace fft {
    vector<int> rev;

    void fft(vector<pt> &y, int on) {
        int n = y.size();
        for (int i = 1; i < n; i++)
            if(i < rev[i]) swap(y[i], y[rev[i]]);
        for (int m = 2; m <= n; m <<= 1) {
            double ang = -on * 2 * PI / m;
            pt wm(cos(ang), sin(ang));
            for (int k = 0; k < n; k += m) {
                pt w(1);
                for (int j = 0; j < m / 2; j++) {
                    pt u = y[k + j];
                    pt t = w * y[k + j + m / 2];
                    y[k + j] = u + t;
                    y[k + j + m / 2] = u - t;
                    w *= wm;
                }
            }
        }
        if (on == -1) for (int i = 0; i < n; i++) y[i].real(real(y[i]) / n);
    }

    vector<ll> mul(const vector<ll> &a, const vector<ll> &b) {
        int n = 1, t = 0, la = a.size(), lb = b.size();
        for (; n <= (la+lb+1); n <<= 1, t++); t = 1<<(t-1);
        vector<pt> x1(n), x2(n);
        rev.assign(n, 0);
        for (int i = 0; i < n; i++) rev[i] = rev[i >> 1] >> 1 | (i & 1 ? t : 0);
        for (int i = 0; i < la; i++) x1[i] = pt(a[i], 0);
        for (int i = 0; i < lb; i++) x2[i] = pt(b[i], 0);
        fft(x1, 1); fft(x2, 1);
        for(int i = 0; i < n; i++) x1[i] *= x2[i];
        fft(x1, -1);
        vector<ll> sol(n);
        for(int i = 0; i < n; i++) sol[i] = real(x1[i]) + 0.5;
        return sol;
    }
}
