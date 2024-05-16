Conversiones de grados sexagesimales a radianes y viceversa.

#include <cmath>

double DegToRad(double d) { 
    return d * acos(-1.0) / 180.0; 
}

double RadToDeg(double r) { 
    return r * 180.0 / acos(-1.0); 
}
