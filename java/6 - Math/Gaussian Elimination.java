Resuelve sistemas de ecuaciones lineales por eliminación Gaussiana. mat[][] contiene los valores de la matriz cuadrada y los resultados de las ecuaciones en la ultima columna. Retorna un vector<> con el valor de las n incongnitas. Los resultados pueden necesitar redondeo.

const int MAX_N = 100;
double mat[MAX_N][MAX_N + 1];
int n;

vector<double> gauss() {
    vector<double> vec(n-1);
    for (int i = 0; i < n - 1; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (abs(mat[j][i]) > abs(mat[pivot][i])) pivot = j;
        for (int j = i; j <= n; j++)
            swap(mat[i][j], mat[pivot][j]);
        for (int j = i + 1; j < n; j++)
            for (int k = n; k >= i; k--)
                mat[j][k] -= mat[i][k]*mat[j][i] / mat[i][i];
    }
    for (int i = n - 1; i >= 0; i--) {
        double temp = 0.0;
        for (int j = i + 1; j < n; j++) temp += mat[i][j]*vec[j];
        vec[i] = (mat[i][n]-temp) / mat[i][i];
    }
    return vec;
}


static int MAX_N = 100;
static double mat[][] = new double[MAX_N][MAX_N + 1];
static int n;

ArrayList<Double> gauss() {
    ArrayList<Double> vec = new ArrayList(n-1);
    for (int i = 0; i < n - 1; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (Math.abs(mat[j][i]) > Math.abs(mat[pivot][i])) pivot = j;
        for (int j = i; j <= n; j++){
            double aux = mat[pivot][j];
            mat[pivot][j] = mat[i][j];
            mat[i][j] = aux;
        }
        for (int j = i + 1; j < n; j++)
            for (int k = n; k >= i; k--)
                mat[j][k] -= mat[i][k]*mat[j][i] / mat[i][i];
    }
    for (int i = n - 1; i >= 0; i--) {
        double temp = 0.0;
        for (int j = i + 1; j < n; j++) temp += mat[i][j]*vec.get(j);
        vec.set(i, (mat[i][n]-temp) / mat[i][i]);
    }
    return vec;
}
