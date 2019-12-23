struct suffixAutomaton {
    struct node {
        int len, link; bool end;
        map<char, int> next;
        ll cnt, in, out;
    };

    vector<node> sa;
    int last; ll substrs = 0;

    suffixAutomaton() {}
    suffixAutomaton(string &s) {
        sa.reserve(s.size()*2);
        last = add_node();
        sa[0].link = -1;
        sa[0].in = 1;
        for (char &c : s) add_char(c);
        for (int p = last; p; p = sa[p].link) sa[p].end = 1;
    }

    int add_node() { sa.pb({}); return sa.size()-1; }

    void add_char(char c) {
        int u = add_node(), p = last;
        sa[u].len = sa[last].len + 1;
        while (p != -1 && !sa[p].next.count(c)) {
            sa[p].next[c] = u;
            sa[u].in += sa[p].in;
            substrs += sa[p].in;
            p = sa[p].link;
        }
        if (p != -1) {
            int q = sa[p].next[c];
            if (sa[p].len + 1 != sa[q].len) {
                int clone = add_node();
                sa[clone] = sa[q];
                sa[clone].len = sa[p].len + 1;
                sa[clone].in = 0;
                sa[q].link = sa[u].link = clone;
                while (p != -1 && sa[p].next[c] == q) {
                    sa[p].next[c] = clone;
                    sa[q].in -= sa[p].in;
                    sa[clone].in += sa[p].in;
                    p = sa[p].link;
                }
            } else sa[u].link = q;
        }
        last = u;
    }

    void run(string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (u && !sa[u].next.count(s[i])) u = sa[u].link;
            if (sa[u].next.count(s[i])) u = sa[u].next[s[i]];
        }
    }

    int match_str(string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (!sa[u].next.count(s[i])) return 0;
            u = sa[u].next[s[i]];
        }
        return count_occ(u);
    }

    int count_occ(int u) {
        if (sa[u].cnt != 0) return sa[u].cnt;
        sa[u].cnt = sa[u].end;
        for (auto v : sa[u].next)
            sa[u].cnt += count_occ(v.S);
        return sa[u].cnt;
    }

    ll count_paths(int u) {
        if (sa[u].out != 0) return sa[u].out;
        for (auto v : sa[u].next)
            sa[u].out += count_paths(v.S) + 1;
        return sa[u].out;
    }
    
    node& operator[](int i) { return sa[i]; }
};
