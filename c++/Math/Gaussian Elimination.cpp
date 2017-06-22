Resuelve sistemas de ecuaciones lineales por eliminación Gaussiana.  matrix contiene los valores de la matriz cuadrada y result los resultados de las ecuaciones. Retorna un vector con el valor de las n incongnitas. Los resultados pueden necesitar redondeo.

#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

const int MAX = 100;
int n = 3;
double matrix[MAX][MAX];
double result[MAX];

vector<double> gauss() {
	vector<double> ans(n, 0);
  double temp;
	for (int i = 0; i < n; i++) {
    int pivot = i;
	  for (int j = i + 1; j < n; j++) {
	   	temp = fabs(matrix[j][i]) - fabs(matrix[pivot][i]);
	    if (temp > numeric_limits<double>::epsilon()) {
	     	pivot = j;
	    }
	  }  
	  swap(matrix[i], matrix[pivot]);
	  swap(result[i], result[pivot]);
	  if (!(fabs(matrix[i][i]) < numeric_limits<double>::epsilon())) {
	    for (int k = i + 1; k < n; k++) {
		    temp = -matrix[k][i] /  matrix[i][i];
		    matrix[k][i] = 0;
		    for (int l = i + 1; l < n; l++) {
		    	matrix[k][l] += matrix[i][l] * temp;
		    }
		  	result[k] += result[i] * temp;
		  }
	  }
  }
  for (int m = n - 1; m >= 0; m--) {
   	temp = result[m];
   	for (int i = n - 1; i > m; i--) {
   		temp -= ans[i] * matrix[m][i];
   	}
   	ans[m] = temp / matrix[m][m];
  }
  return ans;
}
