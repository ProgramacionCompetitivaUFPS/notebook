#include <bits/stdc++.h>

//Cambir valores a, b, c por límites correspondientes
long long a=20, b=20, c=20;
long long acum[a][b][c];
long long INF = -100000000007;

max_range_3D(){
	for(int x=0; x<a; x++){
		for(int y = 0; y<b; y++){
			for(int z = 0; z<c; z++){
				if(x>0) acum[x][y][z] += acum[x-1][y][z];
				if(y>0) acum[x][y][z] += acum[x][y-1][z];
				if(z>0) acum[x][y][z] += acum[x][y][z-1];
				if(x>0 && y>0) acum[x][y][z] -= acum[x-1][y-1][z];
				if(x>0 && z>0) acum[x][y][z] -= acum[x-1][y][z-1];
				if(y>0 && z>0) acum[x][y][z] -= acum[x][y-1][z-1];
				if(x>0 && y>0 && z>0) acum[x][y][z] += acum[x-1][y-1][z-1];
			}
		}
	}
	long long max_value = INF;
	for(int x=0; x<a; x++){
		for(int y = 0; y<b; y++){
			for(int z = 0; z<c; z++){
				for(int h = x; h<a; h++){
					for(int k = y; k<b; k++){
						for(int l = z; l<c; l++){
							long long aux = acum[h][k][l];
							if(x>0) aux -= acum[x-1][k][l];
							if(y>0) aux -= acum[h][y-1][l];
							if(z>0) aux -= acum[x][k][z-1];
							if(x>0 && y>0) aux += acum[x-1][y-1][l];
							if(x>0 && z>0) aux += acum[x-1][k][z-1];
							if(z>0 && y>0) aux += acum[h][y-1][z-1];
							if(x>0 && y>0 && z>0) aux -= acum[x-1][y-1][z-1];
							max_value = max(max_value, aux);
						}
					}
				}
			}
		}
	}
	return max_value;
}
