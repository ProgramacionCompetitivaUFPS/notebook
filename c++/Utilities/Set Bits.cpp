Encender (f = 1) o apagar (f = 0) en a los bits encendidos de b.

int set_bits (int a, int b, bool f) {
    return a ^ ((a ^ f) & b);
}
