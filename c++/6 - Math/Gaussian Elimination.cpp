Resuelve sistemas de ecuaciones lineales por eliminacion Gaussiana. mat[][] contiene los valores de la matriz cuadrada y los resultados de las ecuaciones en la ultima columna. Retorna un vector<> con el valor de las n incongnitas. Los resultados pueden necesitar redondeo.

const int MX = 100;
double mat[MX][MX+1];
int n;
// O(n^3)
vector<double> gauss() {
    vector<double> vec(n-1);
    for (int i = 0; i < n-1; i++) {
        int pivot = i;
        for (int j = i+1; j < n; j++) 
            if (abs(mat[j][i]) > abs(mat[pivot][i])) pivot = j;
        for (int j = i; j <= n; j++) 
            swap(mat[i][j], mat[pivot][j]);
        for (int j = i+1; j < n; j++) 
            for (int k = n; k >= i; k--) 
                mat[j][k] -= mat[i][k]*mat[j][i] / mat[i][i];
    }
    for (int i = n-1; i >= 0; i--) {
        double tmp = 0.0;
        for (int j = i+1; j < n; j++) tmp += mat[i][j]*vec[j];
        vec[i] = (mat[i][n]-tmp) / mat[i][i];
    }
    return vec;
}
