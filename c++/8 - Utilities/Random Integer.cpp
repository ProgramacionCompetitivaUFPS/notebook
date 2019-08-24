Genera un número entero aleatorio en el rango [a, b]. Para long long usar "mt19937_64".

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}
