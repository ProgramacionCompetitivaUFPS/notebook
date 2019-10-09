Resuelve sistemas de ecuaciones lineales por eliminación Gaussiana. mat[][] contiene los valores de la matriz cuadrada y los resultados de las ecuaciones en la ultima columna. Retorna un vector<> con el valor de las N incongnitas. Los resultados pueden necesitar redondeo.

const int MAX = 100;
double mat[MAX][MAX+1];
int N;
/// O(N^3)
vector<double> gauss() {
    vector<double> vec(N-1);
    for (int i = 0; i < N-1; i++) {
        int pivot = i;
        for (int j = i+1; j < N; j++)
            if (abs(mat[j][i]) > abs(mat[pivot][i])) pivot = j;
        for (int j = i; j <= N; j++)
            swap(mat[i][j], mat[pivot][j]);
        for (int j = i+1; j < N; j++)
            for (int k = N; k >= i; k--)
                mat[j][k] -= mat[i][k]*mat[j][i] / mat[i][i];
    }
    for (int i = N-1; i >= 0; i--) {
        double tmp = 0.0;
        for (int j = i+1; j < N; j++) tmp += mat[i][j]*vec[j];
        vec[i] = (mat[i][N]-tmp) / mat[i][i];
    }
    return vec;
}
