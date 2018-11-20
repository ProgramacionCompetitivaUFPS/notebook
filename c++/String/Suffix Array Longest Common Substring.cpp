Busca el substring común mas largo entre dos strings. Retorna un par, con el size del substring y uno de los indices del suffix array. Debe ejecutarse previamente suffixArray() y calculateLCP()

// Los substrings deben estar concatenados de la forma "string1#string2$", antes de ejecutar suffixArray() y calculateLCP()
// m debe almacenar el size del string2.

pair<int, int> longestCommonSubstring() {
  int i, ind = 0, lcs = -1;
  for (i = 1; i < n; i++) {
  	if (((sa[i] < n - m - 1) != (sa[i - 1] < n - m - 1)) && lcp[i] > lcs) { 
       lcs = lcp[i]; ind = i;
    }
  }
  return make_pair(lcs, ind);
}
