Devuelve un vector p donde, para cada i, p[i] es igual al largo del palindromo mas largo con centro en i.
Tener en cuenta que el string debe tener el siguiente formato: %#s[0]#s[1]#...#s[n-1]#$ (s es el string original y n es el largo del string)

vector<int> manacher(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    int c = 0, r = 0;
    for (int i = 1; i < n-1; i++) {
        int j = c - (i-c) ;
        if (r > i) p[i] = min(r-i , p[j]);
        while (s[i+1+p[i]] == s[i-1-p[i]]) 
            p[i]++;
        if (i+p[i] > r) {
            c = i;
            r = i+p[i];
        }
    }
    return p;
}
