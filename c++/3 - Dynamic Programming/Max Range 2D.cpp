// Cambiar infinito por el mínimo valor posible
int INF = -100000007;
int n, m; // filas y columnas
const int MAX_N = 105, MAX_M = 105;
int values[MAX_N][MAX_M];

int max_range_sum2D() {
    for (int i=0; i<n;i++) {
        for (int j=0; j<m; j++) {
            if (i>0) values[i][j] += values[i-1][j];
            if (j>0) values[i][j] += values[i][j-1];
            if (i>0 && j>0) values[i][j] -= values[i-1][j-1];
        }
    }
    int max_mat = INF;
    for (int i=0; i<n;i++) {
        for (int j=0; j<m; j++) {
            for (int h = i; h<n; h++) {
                for (int k = j; k<m; k++) {
                    int sub_mat = values[h][k];
                    if (i>0) sub_mat -= values[i-1][k];
                    if (j>0) sub_mat -= values[h][j-1];
                    if (i>0 && j>0) sub_mat += values[i-1][j-1];
                    max_mat = max(sub_mat, max_mat);
                }
            }
        }
    }
    return max_mat;
}
