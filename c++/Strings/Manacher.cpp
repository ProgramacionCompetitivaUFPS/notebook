Devuelve un vector p donde, para cada i, p[i] es igual al largo del palindromo mas largo con centro en i.

string parse(string &s) {
    string t = "%";
    for (auto &c : s) t.pb('#'), t.pb(c);
    t += "#$";
    return t;
}

vector<int> manacher(string &s) {
    string t = parse(s);
    int n = t.size(), c = 0, r = 0;
    vector<int> p(n, 0);
    for (int i = 1; i < n-1; i++) {
        int j = c - (i-c) ;
        if (r > i) p[i] = min(r-i, p[j]);
        while (t[i+1+p[i]] == t[i-1-p[i]]) 
            p[i]++;
        if (i+p[i] > r) {
            c = i;
            r = i+p[i];
        }
    }
    return p;
    // si p[i] > 0 entonces, s[l, r) es palíndromo
    // donde l = (i-1-p[i])/2 y r = l+p[i];
}
