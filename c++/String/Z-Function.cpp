Este algoritmo encuentra todas las apariciones de un patrón en un texto en tiempo lineal. Sea la longitud del texto n y del patrón m, entonces el tiempo total tomado es O (m + n) con complejidad de espacio lineal.

vector<int> z(string s) {
	int n = s.size();
	vector<int> z(n);
	int x = 0, y = 0;
	for (int i = 1; i < n; i++) {
		z[i] = max(0,min(z[i-x],y-i+1));
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
			x = i; y = i+z[i]; z[i]++;
		}
	}
	return z;
}
