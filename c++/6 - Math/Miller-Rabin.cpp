La función de Miller-Rabin determina si un número dado es o no un número primo.
IMPORTANTE: Debe agregarse los métodos de Random Integers de Utilities, Modular Exponentiation y Modular Multiplication.

bool isPrime(long long p) {
    if (p < 2 || (p != 2 && p % 2 == 0)) return 0;
    long long s = p - 1;
    while (s % 2 == 0) s /= 2;
    for (int i = 0; i < 5; i++) {
        long long a = rand(1, p - 1);
        long long temp = s;
        long long mod = modpow(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1) {
            mod = modmul(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0) return 0;
    }
    return 1;
}