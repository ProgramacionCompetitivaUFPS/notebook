Calcula el area de un polígono representado como un ArrayList de puntos. IMPORTANTE: Definir P[0] = P[n-1] para cerrar el polígono. El algorítmo utiliza el metodo de determinante de la matriz de puntos de la figura. IMPORTANTE: Debe definirse previamente la clase Point.

public static double area(ArrayList<Point> P) {
	double result = 0.0, x1, y1, x2, y2;
  	for (int i = 0; i < P.size()-1; i++) {
    	x1 = P.get(i).getX(); 
    	x2 = P.get(i+1).getX();
    	y1 = P.get(i).getY(); 
    	y2 = P.get(i+1).getY();
    	result += ((x1 * y2) - (x2 * y1));
  	}
  	return Math.abs(result) / 2.0; 
}
