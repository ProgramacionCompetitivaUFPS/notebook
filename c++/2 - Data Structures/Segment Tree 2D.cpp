struct segtree {
    int n, m;
    T neutro = {1, 0, 0, true};
    vector<vector<T>> st;

    segtree(int &n, int &m, vector<vector<T>> &a) : n(n), m(m) {
        st = vector<vector<T>>(2*n, vector<T>(2*m, neutro));
        build(n, m, a);
    }

    T get(T a, T b) {
        return max(a, b);
    }

    void build(int &n, int &m, vector<vector<T>> &a) {
        for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
        st[i + n][j + m] = a[i][j];

        for (int i = 0; i < n; i++) 
        for (int j = m - 1; j; j--) 
        st[i + n][j] = get(st[i + n][j << 1], st[i + n][j << 1 | 1]);

        for (int i = n - 1; i; i--) 
        for (int j = 0; j < 2*m; j++) 
        st[i][j] = get(st[i << 1][j], st[i << 1 | 1][j]);
    }

    T query(int x1, int y1, int x2, int y2) {
        T ans = neutro;
        vector<int> pos(2, 0);
        int node;
        for (x1 += n, x2 += n + 1; x1 < x2; x1 >>= 1, x2 >>= 1) { // rows
            node = 0;
            if (x1&1) pos[node++] = x1++;
            if (x2&1) pos[node++] = --x2;
            for (int it = 0; it < node; it++) {
                for (int l = y1 + m, r = y2 + m + 1; l < r; l >>= 1, r >>= 1) { // cols
                    if (l&1) ans = get(ans, st[pos[it]][l++]);
                    if (r&1) ans = get(ans, st[pos[it]][--r]);
                }
            }
        }
        return ans;
    }

    void upd(int l, int r, T val) {
        st[l + n][r + m] = val;
        for (int j = r + m; j; j >>= 1) 
            st[l][j >> 1] = get(st[l][j], st[l][j + 1]);

        for (int i = l + n; i; i >>= 1) 
            for (int j = r + m; j; j >>= 1) 
                st[i >> 1][j] = get(st[i][j], st[i + 1][j]);
    }
};
