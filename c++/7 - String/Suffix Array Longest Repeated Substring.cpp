Retorna un par con el size y el indice del suffix array en el cual se encuentra el substring repetido mas largo. Debe ejecutarse primero suffixArray() y calculateLCP().

pair<int, int> longestRepeatedSubstring() {
	int ind = -1, lrs = -1;
	for(int i = 0; i < n; i++) if(lrs < lcp[i]) lrs = lcp[i], ind = i;
	return make_pair(lrs, ind);
}