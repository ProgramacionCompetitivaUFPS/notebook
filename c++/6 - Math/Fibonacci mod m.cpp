Calcula fibonacci(n) % m.

long long fib(long long n, long long m) {
    long long a = 0, b = 1, c;
    for (int i = log2(n); i >= 0; i--) {
        c = a;
        a = ((c%m) * (2*(b%m) - (c%m) + m)) % m;
        b = ((c%m) * (c%m) + (b%m) * (b%m)) % m;
        if (((n >> i) & 1) != 0) {
            c = (a + b) % m;
            a = b; b = c;
        }
    }
    return a;
}
