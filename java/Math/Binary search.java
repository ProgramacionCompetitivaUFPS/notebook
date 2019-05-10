static int binary_search(int array[], int n, int x){
	int l = 0; r = n-1;
	while (l <= r) {
		int m = (l+r)/2;
		if(array[m] < x) l = m+1;
		else if (array[m] > x) r = m-1;
		else return m;
	}
	return -1;
}
