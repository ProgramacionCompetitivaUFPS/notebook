El trie (o prefix tree) guarda un diccionario de strings como un arbol enraizado.
Aho corasick permite encontrar las ocurrencias de todos los strings del trie en un string s.

const int alpha = 26; //cantidad de letras del lenguaje
const char L = 'a'; //primera letra del lenguaje

struct node {
    int next[alpha], end;
    //int link, exit, cnt; //para aho corasick
    int& operator[](int i) { return next[i]; }
};

vector<node> trie = {node()};

void add_str(string &s, int id = 1) {
    int u = 0;
    for (auto ch : s) {
        int c = ch-L;
        if (!trie[u][c]) {
            trie[u][c] = trie.size();
            trie.push_back(node());
        }
        u = trie[u][c];
    }
    trie[u].end = id; //con id > 0
    //trie[u].cnt++; //para aho corasick
}

// aho corasick
void build_ac() {
    queue<int> q; q.push(0);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int c = 0; c < alpha; ++c) {
            int nx = trie[u][c];
            if (!nx) continue;
            q.push(nx);
            if (!u) continue;
            node &v = trie[nx];
            v.link = trie[u].link;
            while (v.link && !trie[v.link][c])
                v.link = trie[v.link].link;
            v.link = trie[v.link][c];
            v.exit = trie[v.link].end ? v.link : trie[v.link].exit;
            v.cnt += trie[v.link].cnt; // obtener informacion del padre
        }
    }
}

vector<int> cnt; //cantidad de ocurrencias en s para cada patron

void run_ac(string &s) {
    int u = 0, sz = s.size();
    for (int i = 0; i < sz; ++i) {
        int c = s[i]-L;
        while (u && !trie[u][c]) u = trie[u].link;
        u = trie[u][c];
        int x = u;
        while (x) {
            int id = trie[x].end;
            if (id) cnt[id-1]++;
            x = trie[x].exit;
        }
    }
}