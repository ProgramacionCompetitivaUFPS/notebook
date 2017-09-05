Busca el string p en el string s (definido en init), y retorna un pair con el primer y ultimo indice del suffix array que coinciden con la busqueda. Si no se encuentra, retorna (-1, -1). Debe inicializarse m con el tamaño de p, y debe ejecutarse previamente suffixArray() de Suffix Array Init.cpp.

string p;
int m; 

pair<int, int> stringMatching() {
  if(m - 1 > n) return make_pair(-1, -1);
  char * _s = new char [s.length() + 1]; strcpy (_s, s.c_str());
  char * _p = new char [p.length() + 1]; strcpy (_p, p.c_str());
  int l = 0, h = n - 1, c = l;
  while (l < h) {
    c = (l + h) / 2;
    if(strncmp(_s + sa[c], _p, m - 1) >= 0) h = c;
    else l = c + 1;
  }
  if (strncmp(_s + sa[l], _p, m - 1) != 0) return make_pair(-1, -1);
  pair<int, int> ans; ans.first = l;
  l = 0; h = n - 1; c = l;
  while (l < h) {
    c = (l + h) / 2;
    if (strncmp(_s + sa[c], _p, m - 1) > 0) h = c;
    else l = c + 1;
  }
  if (strncmp(_s + sa[h], _p, m - 1) != 0) h--;
  ans.second = h;
  return ans;
}