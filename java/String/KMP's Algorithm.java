Encuentra si el string pattern se encuentra en el string cadena.

import java.util.ArrayList;

static ArrayList<Integer> table(String pattern){
	int m=pattern.length();
	ArrayList<Integer> border = new ArrayList<Integer>();
	border.add(0);
	int temp;
	for(int i=1; i<m; ++i){
		border.add(border.get(i-1));
		temp = border.get(i);
		while(temp>0 && pattern.charAt(i)!=pattern.charAt(temp)){
			if(temp <= i+1){
				border.set(i,border.get(temp-1));
				temp = border.get(i);
			}
		}
		if(pattern.charAt(i) == pattern.charAt(temp)){
			border.set(i,temp+1);
		}
	}
	return border;
}

static boolean kmp(String cadena, String pattern){
	int n=cadena.length();
	int m=pattern.length();
	ArrayList<Integer> tab=table(pattern);
	int seen=0;

	for(int i=0; i<n; i++){
		while(seen>0 && cadena.charAt(i)!=pattern.charAt(seen)){
			seen=tab.get(seen-1);
		}
		if(cadena.charAt(i)==pattern.charAt(seen))
			seen++;
		if(seen==m){
			return true;
		}
	}
	return false;
}
