Genera un número entero aleatorio en el rango [a, b]. Para long long usar "mt19937_64".

int rand(int a, int b) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<int>(a, b)(rng);
}
