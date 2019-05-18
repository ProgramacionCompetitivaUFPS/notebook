Dado un string s retorna un vector lps donde lps[i] es el largo del prefijo propio más largo que tambien es sufijo de s[0] hasta s[i].
*Para retornar el vector de suffix_link quitar el comentario (//).

vector<int> prefix_function(string s) {
	int n = s.size(), len = 0, i = 1;
	vector<int> lps(n);
	lps[len] = 0;
	while(i < n) {
		if(s[len] != s[i]) {
			if(len) len = lps[len-1];
			else lps[i++] = len;
		} else lps[i++] = ++len;
	}
	//lps.insert(lps.begin(), -1); //Para suffix_link
	return lps;
}
