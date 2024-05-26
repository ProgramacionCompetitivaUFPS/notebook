Encuentra un x tal que para cada i : x es congruente con A_i mod M_i
Devuelve {x, lcm}, donde x es la solucion con modulo lcm (lcm = LCM(M_0, M_1, ...)). Dado un k : x + k*lcm es solucion tambien.
Si la solucion no existe o la entrada no es valida devuelve {-1, -1}
Agregar Extended Euclides.

pair<int, int> crt(vector<int> A, vector<int> M) {
    int n = A.size(), ans = A[0], lcm = M[0];
    for (int i = 1; i < n; i++) {
        int d = euclid(lcm, M[i]);
        if ((A[i] - ans) % d) return {-1, -1};
        int mod = lcm / d * M[i];
        ans = (ans + x * (A[i] - ans) / d % (M[i] / d) * lcm) % mod;
        if (ans < 0) ans += mod;
        lcm = mod;
    }
    return {ans, lcm};
}
