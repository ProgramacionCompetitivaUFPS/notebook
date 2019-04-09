static int upper_bound(int arr[], int n, int x) {
	int l = 0, r = n-1;
	if ( arr[r] <= x) return -1;
	while (l < r) {
		int m = (l+r)/2;
		if(arr[m] > x) r = m;
		else l = m+1;
	}
	return 1;
}
