Encuentra un x tal que para cada i : x es congruente con A_i mod M_i
Devuelve un vector con dos posiciones donde [0] = x && [1] = lcm
donde x es la solución con modulo lcm (lcm = LCM(M_0, M_1, ...)). Dado un k : x + k*lcm es solución tambien.
Si la solución no existe o la entrada no es válida devuelve {-1, -1}
--> Agregar Extended Euclides <--

static int[] crt(ArrayList<Integer> A, ArrayList<Integer> M) {
    int n = A.size(), ans = A.get(0), lcm = M.get(0);
    for (int i = 1; i < n; i++) {
        int d = euclid(lcm, M.get(i));
        if (((A.get(i) - ans) % d) == 1) { int y[] = {-1, -1}; return y; };
        int mod = lcm / d * M.get(i);
        ans = (ans + x * (A.get(i) - ans) / d % (M.get(i) / d) * lcm) % mod;
        if (ans < 0) ans += mod;
        lcm = mod;
    }
    int y[] = {ans, lcm};
    return y;
}
