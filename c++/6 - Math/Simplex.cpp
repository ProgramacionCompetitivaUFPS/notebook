Maximizar la ecuación x1 + x2 + x3 ...
sujeta a restricciones x1 + x2 <= 2, x2 + x3 <= 5 ...
A: matriz de ecuaciones, contiene los coeficientes de cada variable
B: vector con los coeficientes de las restricciones
C: costos de las variables

const double EPS = 1e-6;

struct simplex {
    vector<int> X, Y;
    vector<vector<double>> a;
    vector<double> b, c;
    double z;
    int n, m;

    void pivot(int x, int y) {
        swap(X[y], Y[x]);
        b[x] /= a[x][y];
        for (int i = 0; i < m; i++) {
            if (i != y) a[x][i] /= a[x][y];
        }
        a[x][y] = 1 / a[x][y];
        for (int i = 0; i < n; i++) {
            if (i != x && abs(a[i][y]) > EPS) {
                b[i] -= a[i][y] * b[x];
                for (int j = 0; j < m; j++) {
                    if (j != y) a[i][j] -= a[i][y] * a[x][j];
                }
                a[i][y] =- a[i][y] * a[x][y];
            }
        }
        z += c[y] * b[x];
        for (int i = 0; i < m; i++) {
            if (i != y) c[i] -= c[y] * a[x][i];
        }
        c[y] =- c[y] * a[x][y];
    }

    simplex(vector<vector<double>> &A, vector<double> &B, vector<double> &C) {
        a = A; b = B; c = C;
        n = b.size(); m = c.size(); z = 0.0;
        X.resize(m); iota(X.begin(), X.end(), 0);
        Y.resize(n); iota(Y.begin(), Y.end(), m);
    }

    pair<double, vector<double>> maximize() {
        while (true) {
            int x = -1, y = -1;
            double mn = -EPS;
            for (int i = 0; i < n; i++) {
                if (b[i] < mn) mn = b[i], x = i;
            }
            if (x < 0) break;
            for (int i = 0; i < m; i++) {
                if (a[x][i] < -EPS) {
                    y = i;
                    break;
                }
            }
            assert(y >= 0); // no hay solucion para Ax <= b
            pivot(x, y);
        }
        while (true) {
            double mx = EPS;
            int x = -1, y = -1;
            for (int i = 0; i < m; i++) {
                if (c[i] > mx) mx = c[i], y = i;
            }
            if (y < 0) break;
            double mn = 1e200;
            for (int i = 0; i < n; i++) {
                if (a[i][y] > EPS && b[i] / a[i][y] < mn) 
                mn = b[i] / a[i][y], x = i;
            }
            assert(x >= 0); // unbounded
            pivot(x, y);
        }
        vector<double> r(m);
        for (int i = 0; i < n; i++) {
            if (Y[i] < m) r[Y[i]] = b[i];
        }
        return {z, r};
    }
};
