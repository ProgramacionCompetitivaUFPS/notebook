Estructura de datos que permite procesar consultas por rangos y actualizaciones individuales sobre un arreglo.
Recibe como parametro en el constructor un arreglo de valores.
IMPORTANTE: Para para procesar actualizaciones por rangos se deben descomentar los lineas de Lazy Propagation.

struct SegmentTree {
    vector<int> st;//, lazy;
    int n, neutro = 1 << 30;

    SegmentTree(vector<int> &arr) {
        n = arr.size();
        st.assign(n << 2, 0);
        //lazy.assign(n << 2, neutro);
        build(1, 0, n - 1, arr);
    }

    int query(int i, int j) { return query(1, 0, n - 1, i, j); }
    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int left (int p) { return p << 1; }
    int right (int p) { return (p << 1) | 1; }

    void build(int p, int L, int R, vector<int> &arr) {
        if (L == R) st[p] = arr[L];
        else {
            int m = (L+R)/2, l = left(p), r = right(p);
            build(l, L, m, arr);
            build(r, m+1, R, arr);
            st[p] = min(st[l], st[r]);
        }
    }
    /*
    void propagate(int p, int L, int R, int val) {
        if (val == neutro) return;
        st[p] = val;
        lazy[p] = neutro;
        if (L != R) {
            lazy[left(p)] = val;
            lazy[right(p)] = val;
        }
    }
    */
    int query(int p, int L, int R, int i, int j) {
        //propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return neutro;
        if (i <= L && j >= R) return st[p];
        int m = (L+R)/2, l = left(p), r = right(p);
        l = query(l, L, m, i, j);
        r = query(r, m+1, R, i, j);
        return min(l, r);
    }

    void update(int p, int L, int R, int i, int j, int val) {
        //propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return;
        if (i <= L && j >= R) st[p] = val;//propagate(p, L, R, val);
        else {
            int m = (L+R)/2, l = left(p), r = right(p);
            update(l, L, m, i, j, val);
            update(r, m+1, R, i, j, val);
            st[p] = min(st[l], st[r]);
        }
    }
};