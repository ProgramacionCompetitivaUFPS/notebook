Calcula el array Longest Common Prefix para todo el suffix array. IMPORTANTE: Debe haberse ejecutado primero suffixArray(), incluido en Suffix Array Init.cpp

int lcp[N_MAX];

void calculateLCP() {
  for (int i = 0; i < n; i++) rk[sa[i]] = i;
  for (int i = 0, l = 0; i < n; i++) {
    if (rk[i] > 0) {
      int j = sa[rk[i] - 1];
      while (s[i + l] == s[j + l]) l++;
      lcp[rk[i]] = l;
      if(l > 0) l--;
    }
  }
}