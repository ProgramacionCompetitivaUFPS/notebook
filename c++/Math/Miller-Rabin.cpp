La función de Miller-Rabin determina si un número dado es o no un número primo.

#include <cstdlib>


long long mulmod(long long a, long long b, long long mod){
    long long x = 0;
    long long y = a % mod;
    while (b > 0){
        if (b % 2 == 1){    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

long long modulo(long long base, long long exponent, long long mod){
    long long x = 1;
    long long y = base;
    while (exponent > 0){
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 

bool miller(long long  p)
{
    if (p < 2){
        return false;
    }
    if (p != 2 && p % 2==0){
        return false;
    }
    long long s = p - 1;
    while (s % 2 == 0){
        s /= 2;
    }
    for (int i = 0; i < 5; i++){
        long long a = rand() % (p - 1) + 1;
        long long temp = s;
        long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1){
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0){
            return false;
        }
    }
    return true;
}
