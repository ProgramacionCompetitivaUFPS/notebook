Encuentra si el string pattern se encuentra en el string cadena. Debe estar definido el método prefix_function.

static boolean kmp(String cadena, String pattern) {
	int n=cadena.length();
	int m=pattern.length();
	int[] tab=prefix_function(pattern);
	for(int i = 0, seen = 0; i < n; i++) {
		while(seen > 0 && cadena.charAt(i) != pattern.charAt(seen)) {
			seen = tab[seen-1];
		}
		if(cadena.charAt(i) == pattern.charAt(seen)) seen++;
		if(seen == m) return true;
	}
	return false;
}
