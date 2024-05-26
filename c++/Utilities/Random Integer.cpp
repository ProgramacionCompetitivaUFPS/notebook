Genera un numero entero aleatorio en el rango [a, b]. Para ll usar "mt19937_64" y cambiar todo a ll.

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
