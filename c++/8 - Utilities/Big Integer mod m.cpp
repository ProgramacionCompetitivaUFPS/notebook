Calcula n % m. Utilizar cuando n es un número muy muy grande.

int mod(string &n, int m) {
    int r = 0;
    for (char c : n)
        r = (r*10 + (c-'0')) % m; 
    return r;
}
