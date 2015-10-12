Encuentra si el string pattern se encuentra en el string cadena.

#include <vector>

vector<int> table(string pattern){
	int m=pattern.size();
	vector<int> border(m);
	border[0]=0;

	for(int i=1; i<m; ++i){
		border[i]=border[i-1];
		while(border[i]>0 && pattern[i]!=pattern[border[i]]){
			border[i]=border[border[i]-1];
		}
		if(pattern[i] == pattern[border[i]]){
			border[i]++;
		}
	}
	return border;
}

bool kmp(string cadena, string pattern){
	int n=cadena.size();
	int m=pattern.size();
	vector<int> tab=table(pattern);
	int seen=0;

	for(int i=0; i<n; i++){
		while(seen>0 && cadena[i]!=pattern[seen]){
			seen=tab[seen-1];
		}
		if(cadena[i]==pattern[seen])
			seen++;
		if(seen==m){
			return true;
		}
	}
	return false;
}
