vector<int> manacher(string S) {
	int n = S.size();
	vector<int> P(n, 0);
	int C = 0, R = 0;
	for (int i = 1; i < n-1; i++) {
		int j = C - (i - C) ;
		if (R > i) P[i] = min(R - i , P[j]);
		while (S[i + 1 + P[i]] == S[i - 1 - P[i]])
			P[i]++;
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}
	return P;
}