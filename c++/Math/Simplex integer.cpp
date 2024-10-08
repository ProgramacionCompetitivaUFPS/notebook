Resuelve el problema de Linear Integer Programming (LPI).
Agregar Fraction con tipo de dato __int128 y hacer los siguientes ajustes:

// Cambiar el tipo de dato del Simplex a Fraction
typedef Fraction lf;

// Agregar constantes
const Fraction ZERO, INF(1e18);

// Cambiar las siguientes líneas en el Simplex
z = ZERO; // Línea 19
a[x][y] = Fraction(1) / a[x][y]; // Línea 30
if (i != x && a[i][y] != ZERO) { // Línea 32
lf mn = ZERO; // Línea 50
if (a[x][i] < ZERO) { // Línea 56
lf mx = ZERO; // Línea 65
lf mn = INF; // Línea 71
if (a[i][y] > ZERO && b[i] / a[i][y] < mn)  // Línea 73

// Agregar el siguiente método en el Simplex
pair<Fraction, vector<Fraction>> maximize_int() {
    while (true) {
        auto sol = maximize();
        bool all_int = true;
        for (auto &x : sol.S) all_int &= x.fractional_part() == ZERO;
        if (all_int) return sol;

        Fraction nw_b = ZERO;
        int id = -1;
        for (int i = 0; i < n; i++) {
            Fraction fp = b[i].fractional_part();
            if (fp >= nw_b) nw_b = fp, id = i;
        }
        vector<Fraction> nw_a;
        for (auto &x : a[id]) nw_a.pb(-x.fractional_part());
        a.pb(nw_a);
        b.pb(-nw_b);
        Y.pb(n+m); n++;
    }
}
