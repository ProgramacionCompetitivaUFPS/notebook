const int alfa = 26;
const char L = 'a';

struct node {
    int next[alfa], link, len;
    ll cnt;
    node(int x, int l = 0, ll c = 1): len(x), link(l), cnt(c) {
        memset(next, 0, sizeof next);
    }
    int& operator [] (int i) { return next[i]; }
};

struct palindromic_tree {
    vector<node> tree;
    string s;
    int n;
    int last;
    palindromic_tree(string t = "") {
        n = last = 0;
        tree.pb(node(-1));
        tree.pb(node(0));
        for (auto &c: t)add_char(c);
    }

    int getlink(int p) {
        while (s[n - tree[p].len - 1] != s[n])p = tree[p].link;
        return p;
    }

    void add_char(char ch) {
        s.pb(ch);
        int p = getlink(last), c = ch - L;
        if (!tree[p][c]) {
            int link = getlink(tree[p].link);
            link = max(1, tree[link][c]);
            tree[p][c] = SZ(tree);
            tree.pb(node(tree[p].len + 2,link, 0));
        }
        last = tree[p][c];
        tree[last].cnt++;
        n++;
    }
};
