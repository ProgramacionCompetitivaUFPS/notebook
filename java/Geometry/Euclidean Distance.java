Halla la distancia euclideana de 2 puntos en dos dimensiones (x,y). 

/*Trabajando con los valores x y y de cada punto*/
double euclideanDistance(double x1, double y1, double x2, double y2){ 
    return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));         
} 
