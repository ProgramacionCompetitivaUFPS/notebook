Encuentra si el string pattern se encuentra en el string cadena. Debe estar definido el método prefix_function.

#include <vector>

bool kmp(string cadena, string pattern) {
	int n=cadena.size();
	int m=pattern.size();
	vector<int> tab=prefix_function(pattern);

	for(int i = 0, seen = 0; i < n; i++) {
		while(seen > 0 && cadena[i] != pattern[seen]) {
			seen = tab[seen-1];
		}
		if(cadena[i] == pattern[seen]) seen++;
		if(seen == m) return true;
	}
	return false;
}
