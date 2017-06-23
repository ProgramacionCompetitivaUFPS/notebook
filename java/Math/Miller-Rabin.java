La función de Miller-Rabin determina si un número dado es o no un número primo. IMPORTANTE: Debe utilizarse el método binaryExponentiation y Modular Multiplication.

public static boolean miller (long p) {
  if (p < 2 || (p != 2 && p % 2==0)) return false;
  long s = p - 1;
  while (s % 2 == 0) s /= 2;
  for (int i = 0; i < 5; i++){
    long a = (long)(Math.random() * 100000000) % (p - 1) + 1;
    long temp = s;
    long mod = binaryExponentiation(a, temp, p);
    while (temp != p - 1 && mod != 1 && mod != p - 1){
      mod = mulmod(mod, mod, p);
      temp *= 2;
    }
    if (mod != p - 1 && temp % 2 == 0) return false;
  }    
  return true;
}
