(Prefix tree) Estructura de datos para almacenar un diccionario de strings. Debe ejecutarse el método init_trie. El método dfs hace un recorrido en orden del trie.

const int MAX_L = 26; //cantidad de letras del lenguaje
char L = 'a'; //primera letra del lenguaje

struct node {
    int next[MAX_L];
    bool fin;
    node() {
        memset(next, -1, sizeof(next));
        fin = 0;
    }
};

vector<node> trie;

void init_trie() {
    trie.clear();
    trie.push_back(node());
}

void add_str(string s) {
    int cur = 0;
    for (auto c : s) {
        if (trie[cur].next[c-L] == -1) {
            trie[cur].next[c-L] = trie.size();
            trie.push_back(node());
        }
        cur = trie[cur].next[c-L];
    }
    trie[cur].fin = 1;
}


bool contain(string s) {
    int cur = 0;
    for (auto c : s) {
        if (trie[cur].next[c-L] == -1) return 0;
        cur = trie[cur].next[c-L];
    }
    return trie[cur].fin;
}

void dfs(int cur){
    for (int i = 0; i < MAX_L; ++i) {
        if (trie[cur].next[i] != -1) {
            //cout << (char)(i+L) << endl;
            dfs(trie[cur].next[i]);
        }
    }
}

int main() {
    init_trie();
    string s[] = {"hello", "world", "help"};
    for (auto c : s) add(c);
    return 0;
}
