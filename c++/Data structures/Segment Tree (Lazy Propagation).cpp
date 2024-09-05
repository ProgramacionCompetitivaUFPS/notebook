> Dado un vector de valores permite hacer consultas sobre rangos y actualizaciones individuales en O(log n). Construcción en O(n).
> Para hacer actualizaciones sobre rangos se deben descomentar las lineas de Lazy Propagation.
> El valor neutro depende del tipo de consulta. Para sumas: 0, mínimos: infinito, máximos: -infinito, etc.

typedef int T; // tipo de dato del segtree
struct segtree {
    vector<T> st; // , lazy;
    int n; T neutro = 1e9; // "infinito"

    segtree(const vector<int> &v) {
        n = v.size();
        st.assign(n*4, 0);
        // lazy.assign(n*4, neutro);
        build(1, 0, n-1, v);
    }

    void build(int p, int L, int R, const vector<int> &v) {
        if (L == R) st[p] = v[L];
        else {
            int m = (L+R)/2, l = p*2, r = l+1;
            build(l, L, m, v);
            build(r, m+1, R, v);
            st[p] = min(st[l], st[r]);
        }
    }
    /*
    void propagate(int p, int L, int R, T val) {
        if (val == neutro) return;
        st[p] = val;
        lazy[p] = neutro;
        if (L == R) return;
        int l = p*2, r = l+1;
        lazy[l] = lazy[r] = val;
    }
    */
    T query(int i, int j) { return query(1, 0, n-1, i, j); }
    void upd(int i, int j, T val) { upd(1, 0, n-1, i, j, val); }

    T query(int p, int L, int R, int i, int j) {
        // propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return neutro;
        if (i <= L && j >= R) return st[p];
        int m = (L+R)/2, l = p*2, r = l+1;
        T lf = query(l, L, m, i, j);
        T rg = query(r, m+1, R, i, j);
        return min(lf, rg);
    }

    void upd(int p, int L, int R, int i, int j, T val) {
        // propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return;
        if (i <= L && j >= R) st[p] = val; // cambiar por propagate(p, L, R, val);
        else {
            int m = (L+R)/2, l = p*2, r = l+1;
            upd(l, L, m, i, j, val);
            upd(r, m+1, R, i, j, val);
            st[p] = min(st[l], st[r]);
        }
    }
};
