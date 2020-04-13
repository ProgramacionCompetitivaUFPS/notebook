const int MAXL = 26; //cantidad de letras del lenguaje
char L = 'a'; //primera letra del lenguaje

struct node {
    int next[MAXL], go[MAXL];
    int p, link = -1;
    char pch;
    vector<int> end;

    node(int p = -1, char pch = -1) : p(p), pch(pch) {
        memset(next, -1, sizeof(next));
        memset(go, -1, sizeof(go));
    }
};

vector<node> trie;

void init_trie() { trie.assign(1, node()); }

void add_str(string &s, int id) {
    int u = 0;
    for (auto ch : s) {
        int c = ch-L;
        if (trie[u].next[c] == -1) {
            trie[u].next[c] = trie.size();
            trie.pb(node(u, ch));
        }
        u = trie[u].next[c];
    }
    trie[u].end.pb(id);
}

int go(int u, char ch);

int get_link(int u) {
    if (trie[u].link == -1) {
        if (!u || !trie[u].p) trie[u].link = 0;
        else trie[u].link = go(get_link(trie[u].p), trie[u].pch);
    }
    return trie[u].link;
}

int go(int u, char ch) {
    int c = ch-L;
    if (trie[u].go[c] == -1) {
        if (trie[u].next[c] != -1) trie[u].go[c] = trie[u].next[c];
        else trie[u].go[c] = u == 0 ? 0 : go(get_link(u), ch);
    }
    return trie[u].go[c];
}

vector<int> cnt;

void proc(int u) {
    while (u) {
        for (auto id : trie[u].end) cnt[id]++;
        u = get_link(u);
    }
}

inline void ac_run(string &s) {
    int n = s.size();
    for (int u = 0, i = 0; i < n; ++i) {
        u = go(u, s[i]);
        proc(u);
    }
}
