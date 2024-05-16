Dado un string s retorna un array pf donde pf[i] es el largo del prefijo propio más largo
que tambien es sufijo de cad[0] hasta cad[i].
El String debe pasarse como un array de chars cadena.toCharArray();
// O(n)

static int[] prefix_function(char[] cad) {
    int n = cad.length;
    int pf[] = new int[n];
    pf[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j==1 && cad[i] != cad[j]) j = pf[j-1];
        if (cad[i] == cad[j]) j++;
        pf[i] = j;
    }
    return pf;
}
