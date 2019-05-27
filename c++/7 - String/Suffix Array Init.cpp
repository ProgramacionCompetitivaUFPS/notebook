Crea el suffix array. Deben inicializarse las variables s (String original), N_MAX (Máximo size que puede tener s), y n (Size del string actual).

string s;
const int N_MAX;
int n; 
int sa[N_MAX];
int rk[N_MAX];
long long rk2[N_MAX];

bool _cmp(int i, int j) { 
  return rk2[i] < rk2[j];
}

void suffixArray() {
  for (int i = 0; i < n; i++) {
    sa[i] = i; rk[i] = s[i]; rk2[i] = 0;
  }
  for (int l = 1; l < n; l <<= 1) {
    for (int i = 0; i < n; i++) {
      rk2[i] = ((long long) rk[i] << 32) + (i + l < n ? rk[i + l] : -1);
    }
    sort(sa, sa + n, _cmp);
    for (int i = 0; i < n; i++) {
      if (i > 0 && rk2[sa[i]] == rk2[sa[i - 1]]) 
        rk[sa[i]] = rk[sa[i - 1]]; 
      else rk[sa[i]] = i;
    }
  }
}