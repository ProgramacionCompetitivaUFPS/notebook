Dado un arreglo A con n numeros calcula en basis[] las mascaras con las cuales se pueden generar todos los diferentes xor que se generan al hacer xor entre los elementos de cualquier subconjunto A. La cantidad de xor diferentes es 2^sz.

const int D = 30; //maxima cantidad de bits
int basis[D];
int sz; //cantidad de mascaras en la base

/// O(n*D)
void insertVector(int mask) {
    for (int i = 0; i < D; ++i) {
        if (mask & (1<<i)) {
            if (!basis[i]) {
                basis[i] = mask;
                ++sz;
                break;
            }
            mask ^= basis[i];
        }
    }
}