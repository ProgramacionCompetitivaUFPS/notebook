Realiza la operación (n!) % mod.

public static long modfact(int n, int mod) {
    long temp = 1;
    while (n > 1) {
        temp = temp * n % mod;
        n--;
    }
    return temp;
}
