calcula la distancia minima entre un punto y una linea

double minDistance(Point A, Point B, Point E) {
  pair<double, double> AB;
  AB.F = B.F - A.F;
  AB.S = B.S - A.S;
  pair<double, double> BE;
  BE.F = E.F - B.F;
  BE.S = E.S - B.S;
  pair<double, double> AE;
  AE.F = E.F - A.F, AE.S = E.S - A.S;
  double AB_BE, AB_AE;
  AB_BE = (AB.F * BE.F + AB.S * BE.S);
  AB_AE = (AB.F * AE.F + AB.S * AE.S);
  double reqAns = 0;
  if (AB_BE > 0) {
    double y = E.S - B.S;
    double x = E.F - B.F;
    reqAns = sqrt(x * x + y * y);
  } else if (AB_AE < 0) {
    double y = E.S - A.S;
    double x = E.F - A.F;
    reqAns = sqrt(x * x + y * y);
  } else {
    double x1 = AB.F;
    double y1 = AB.S;
    double x2 = AE.F;
    double y2 = AE.S;
    double mod = sqrt(x1 * x1 + y1 * y1);
    reqAns = abs(x1 * y2 - y1 * x2) / mod;
  }
  return reqAns;
}