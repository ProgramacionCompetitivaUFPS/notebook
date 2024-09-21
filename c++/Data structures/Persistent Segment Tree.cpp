> Guarda el estado del segment tree después de cada actualización para permitir hacer consultas sobre estados pasados.
> Consultas y actualizaciones en O(logn), ocupa O(nlogn) en memoria.

struct node {
    node *left, *right;
    int val;

    node() : left(this), right(this), val(0) {}
    node(node *left, node *right, int val) :
        left(left), right(right), val(val) {}

    node* update(int l, int r, int i, int x) {
        if (l == r) return new node(nullptr, nullptr, val + x);
        int m = (l + r) / 2;
        if (i <= m)
            return new node(left->update(l, m, i, x), right, val + x);
        return new node(left, right->update(m + 1, r, i, x), val + x);
    }

    int query(int l, int r, int i, int j) {
        if (i > r || l > j) return 0;
        if (i <= l && r <= j) return this->val;
        int m = (l + r) / 2;
        int lf = left->query(l, m, i, j);
        int rg = right->query(m + 1, r, i, j);
        return lf + rg;
    }
};

vector<node*> roots = {new node()};
roots.pb(roots.back()->update(0, n-1, i, x));
roots[i]->query(0, n-1, l, r);
