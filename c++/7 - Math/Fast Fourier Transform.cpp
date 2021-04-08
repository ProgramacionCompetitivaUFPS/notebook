Multiplicacion de polinomios en O(n log n)

const double PI = acos(-1.0);
 
namespace fft {
    struct pt {
        double r, i;
        pt(double r = 0.0, double i = 0.0) : r(r), i(i) {}
        pt operator + (const pt &b) { return pt(r+b.r, i+b.i); }
        pt operator - (const pt &b) { return pt(r-b.r, i-b.i); }
        pt operator * (const pt &b) { return pt(r*b.r - i*b.i, r*b.i + i*b.r); }
    };
    vector<int> rev;
 
    void fft(vector<pt> &y, int on) {
        int n = y.size();
        for (int i = 1; i < n; i++)
            if (i < rev[i]) swap(y[i], y[rev[i]]);
        for (int m = 2; m <= n; m <<= 1) {
            double ang = -on * 2 * PI / m;
            pt wm(cos(ang), sin(ang));
            for (int k = 0; k < n; k += m) {
                pt w(1, 0);
                for (int j = 0; j < m / 2; j++) {
                    pt u = y[k + j];
                    pt t = w * y[k + j + m / 2];
                    y[k + j] = u + t;
                    y[k + j + m / 2] = u - t;
                    w = w * wm;
                }
            }
        }
        if (on == -1) for (int i = 0; i < n; i++) y[i].r /= n;
    }
 
    vector<ll> mul(vector<ll> &a, vector<ll> &b) {
        int n = 1, t = 0, la = a.size(), lb = b.size();
        for (; n <= (la+lb+1); n <<= 1, t++); t = 1<<(t-1);
        vector<pt> x1(n), x2(n);
        rev.assign(n, 0);
        for (int i = 0; i < n; i++) rev[i] = rev[i >> 1] >> 1 | (i & 1 ? t : 0);
        for (int i = 0; i < la; i++) x1[i] = pt(a[i], 0);
        for (int i = 0; i < lb; i++) x2[i] = pt(b[i], 0);
        fft(x1, 1); fft(x2, 1);
        for (int i = 0; i < n; i++) x1[i] = x1[i] * x2[i];
        fft(x1, -1);
        vector<ll> ans(n);
        for (int i = 0; i < n; i++) ans[i] = x1[i].r + 0.5;
        return ans;
    }
}