Dados 3 puntos A, B, y C, determina el valor del angulo ABC (origen en B) en radianes. IMPORTANTE: Definir la estructura point y vec (Geometric Vector). Si se desea convertir a grados sexagesimales, revisar Sexagesimal degrees and radians.

#include <vector>
#include <cmath>

double angle(point a, point b, point c) { 
  vec ba = toVector(b, a);
  vec bc = toVector(b, c);
  return acos((ba.x * bc.x + ba.y * bc.y) / sqrt((ba.x * ba.x + ba.y * ba.y) * (bc.x * bc.x + bc.y * bc.y))); 
}
