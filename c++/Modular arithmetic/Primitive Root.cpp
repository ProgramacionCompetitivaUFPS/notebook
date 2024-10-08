g es una raíz primitiva módulo n si y solo si para cualquier entero a tal que gcd(a, n) = 1, existe un entero k tal que: g^k = a mod n.
La raíz primitiva módulo n existe si y solo si: n = 1, 2, 4, o n = p^k, o n = 2 * p^k, donde p es un número primo impar.
Agregar Modular Exponentiation.

// O(ans * log(phi(p)) * log(p))
int primitive_root(int p) { // Función para cuando p es primo
    vector<int> fact;
    int phi = p-1, n = phi; // Si p no es primo, calcular Euler totient de p.
    for (int i = 2; i*i <= n; ++i) 
        if (n%i == 0) {
            fact.push_back(i);
            while (n%i == 0) n /= i;
        }
    if (n > 1) fact.push_back(n);
    
    for (int ans = 2; ans <= p; ++ans) {
        bool ok = true;
        for (int i = 0; i < fact.size() && ok; ++i) 
            ok &= expmod(ans, phi / fact[i], p) != 1;
        if (ok) return ans;
    }
    return -1;
}
