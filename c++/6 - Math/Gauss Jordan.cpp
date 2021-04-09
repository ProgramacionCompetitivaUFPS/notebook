Algoritmo de eliminación Gauss-Jordan O(N ^ 3)
Soluciona un sistema de ecuaciones de la forma:
a11 x1 + a12 x2 + ... + a1m xm = b1
a21 x1 + a22 x2 + ... + a2m xm = b2
an x1 + an2 x2 + ... + anm xm = bn

El vector a contiene los valores de la matriz, cada fila es una ecuación, la última columna contiene los valores b.

const int EPS = 1;
int gauss (vector<vector<int>>& a, vector<int> &ans) {
  int n = a.size(), m = a[0].size()-1;
  vector<int> where(m, -1);
  for(int col = 0, row = 0; col < m && row < n; ++col) {
    int sel = row;
    for(int i = row; i < n; ++i)
      if(abs(a[i][col]) > abs(a[sel][col])) sel = i;
    if(abs(a[sel][col]) < EPS) continue;
    swap(a[sel], a[row]);
    where[col] = row;
    for(int i = 0; i < n; ++i)
      if(i != row) {
        int c = divide(a[i][col], a[row][col]); 
        for(int j = col; j <= m; ++j)
          a[i][j] = sub(a[i][j], mul(a[row][j], c));
      }
    ++row;
  }
  ans.assign(m, 0);
  for(int i = 0; i < m; ++i)
    if(where[i] != -1) ans[i] = divide(a[where[i]][m], a[where[i]][i]);
  for(int i = 0; i < n; ++i) {
    int sum = 0;
    for(int j = 0; j < m; ++j)
      sum = add(sum, mul(ans[j], a[i][j]));
    if(sum != a[i][m]) return 0;
  }
  for(int i = 0; i < m; ++i)
    if(where[i] == -1) return -1; 
  return 1;
}


Gauss jordan para operaciones de xor

int gauss (vector<bitset<N>> &a, vector<bitset<N>> &b, int n, int m, vector<bitset<N>> &ans) {
  vector<int> where(m, -1);
  for(int col = 0, row = 0; col < m && row < n; ++col) {
    for(int i = row; i < n; ++i){
      if(a[i][col]){
        swap(a[i], a[row]);
        swap(b[i], b[row]);
        break;
      }
    }
    if(!a[row][col])continue;
    where[col] = row;
    for(int i = 0; i < n; ++i)
      if(i != row && a[i][col]) {
        a[i] ^= a[row];
        b[i] ^= b[row];
      }
    ++row;
  }
  ans.assign(m, 0);
  for(int i = 0; i < m; ++i)
    if(where[i] != -1) ans[i] = b[where[i]];
  for(int i = 0; i < n; ++i) {
    if(ans[i] == 0) return 0;
  }
  for(int i = 0; i < m; ++i)
    if(where[i] == -1) return -1; /// infinite solutions
  return 1;
}