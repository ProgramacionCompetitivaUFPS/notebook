ArrayList<Integer> manacher(String S) {
	int n = S.length();
	ArrayList<Integer> P = new ArrayList(n);
	int C = 0, R = 0;
	for (int i = 1; i < n-1; i++) {
		int j = C - (i - C) ;
		if (R > i) P.set(i, Math.min(R - i , P.get(j)));
		while (S.charAt(i + 1 + P.get(i)) == S.charAt(i - 1 - P.get(i)))
                    P.set(i, P.get(i)+1);
		if (i + P.get(i) > R) {
			C = i;
			R = i + P.get(i);
		}
	}
	return P;
}
