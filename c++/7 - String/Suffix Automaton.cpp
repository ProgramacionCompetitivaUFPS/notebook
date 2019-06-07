Utilizar el metodo suffixAutomaton() luego de leer el string s para construir el automata de sufijos.

struct state {
    int len, link;
    long long paths_in, paths_out;
    map<char, int> next;
    bool terminal;
};

const int MAX_N = 100001;
state sa[MAX_N<<1];
int sz, last;
long long paths;
string s;

void sa_add(char c) {
    int cur = sz++, p;
    sa[cur] = {sa[last].len + 1, 0, 0, 0, map<char, int>(), 0};
    for (p = last; p != -1 && !sa[p].next.count(c); p = sa[p].link) {
        sa[p].next[c] = cur;
        sa[cur].paths_in += sa[p].paths_in;
        paths += sa[p].paths_in;
    }
    if (p != -1) {
        int q = sa[p].next[c];
        if (sa[p].len + 1 != sa[q].len) {
            int clone = sz++;
            sa[clone] = {sa[p].len + 1, sa[q].link, 0, 0, sa[q].next, 0};
            for (; p != -1 && sa[p].next[c] == q; p = sa[p].link) {
                sa[p].next[c] = clone;
                sa[q].paths_in -= sa[p].paths_in;
                sa[clone].paths_in += sa[p].paths_in;
            }
            sa[q].link = sa[cur].link = clone;
        } else sa[cur].link = q;
    }
    last = cur;
}

void suffixAutomaton() {
    sz = 1; last = paths = 0;
    sa[0] = {0, -1, 1, 0, map<char, int>(), 1};
    for (char c : s) sa_add(c);
    for(int p = last; p != 0; p = sa[p].link) sa[p].terminal = 1;
}

void sa_run(string p) {
    int n = p.size();
    for (int cur = 0, i = 0; i < n; ++i) {
        if (sa[i].next.count(p[i])) cur = sa[cur].next[p[i]];
        else cur = max(sa[cur].link, 0);
    }
}

long long sa_count_paths_out(int cur) {
    if (!sa[cur].next.size()) return 0;
    if (sa[cur].paths_out != 0) return sa[cur].paths_out;
    for (auto i : sa[cur].next)
        sa[cur].paths_out += 1 + sa_count_paths_out(i.second);
    return sa[cur].paths_out;
}

int memo[MAX_N<<1];

int sa_count_ocurrences(int cur) {
    if (sa[cur].next.empty()) memo[cur] = 1;
    if (memo[cur] != -1) return memo[cur];
    memo[cur] = sa[cur].terminal;
    for (auto i : sa[cur].next)
        memo[cur] += sa_count_ocurrences(i.second);
    return memo[cur];
}

//Para retornar booleano cambiar el primer return por false y el segundo por true
int sa_string_matching(string p) {
    int m = p.size(), cur = 0;
    for (int i = 0; i < m; ++i) {
        if (!sa[i].next.count(p[i])) return 0;
        else cur = sa[cur].next[p[i]];
    }
    return sa_count_ocurrences(cur);
}

//Requiere contruir el automata de (s+s)
int sa_lexico_min() {
    int n = s.size()>>1, cur = 0;
    for (int i = 0; i < n; ++i) cur = (*(sa[cur].next.begin())).second;
    return sa[cur].len-n;
}
