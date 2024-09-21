> Agregar líneas en orden no-creciente por pendiente m. Permite consultar el mínimo f(x). Para máximo, cambiar el signo de las lineas: -m, -h.

typedef ll T;
struct line { T m, h; };
struct cht {
    vector<line> c;
    int pos = 0;

    T inter(line a, line b) {
        T x = b.h-a.h, y = a.m-b.m;
        return x/y + (x%y ? (x>0)==(y>0) : 0); // == ceil(x/y)
    }

    void add(T m, T h) {
        line l = {m, h};
        if (c.size() && m == c.back().m) {
            l.h = min(h, c.back().h);
            c.pop_back(); if (pos) pos--;
        }
        while (c.size() > 1 && inter(c.back(), l) <= inter(c[c.size()-2], c.back())) {
            c.pop_back(); if (pos) pos--;
        }
        c.pb(l);
    }

    inline bool fbin(T x, int m) { return inter(c[m], c[m+1]) > x; }

    T query(T x) {
        // O(log n) query:
        int l = 0, r = c.size();
        while (r-l > 1) {
            int m = (l+r)/2;
            if (fbin(x, m-1)) r = m;
            else l = m;
        }
        return c[l].m*x + c[l].h;
        // O(1) query (para x's ordenadas):
        while (pos > 0 && fbin(x, pos-1)) pos--;
        while (pos < (int)c.size()-1 && !fbin(x, pos)) pos++;
        return c[pos].m*x + c[pos].h;
    }
};
