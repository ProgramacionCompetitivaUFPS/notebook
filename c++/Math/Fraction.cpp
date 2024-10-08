Estructura para trabajar con fracciones como un tipo de dato

typedef ll T;
struct Fraction {
    T num, den;

    Fraction() : num(0), den(1) {}
    Fraction(T n) : num(n), den(1) {}
    Fraction(T n, T d) : num(n), den(d) { reduce(); }

    void reduce() {
        assert(den != 0);
        T gcd = __gcd(num, den);
        num /= gcd, den /= gcd;
        if (den < 0) num = -num, den = -den;
    }
    Fraction fractional_part() const { // x - floor(x)
        Fraction fp = Fraction(num % den, den);
        if (fp < Fraction(0)) fp += Fraction(1);
        return fp;
    }
    T compare(Fraction f) const {
        return num * f.den - den * f.num;
    }
    Fraction operator + (const Fraction& f) {
        return Fraction(num * f.den + den * f.num, den * f.den);
    }
    Fraction operator - (const Fraction& f) {
        return Fraction(num * f.den - den * f.num, den * f.den);
    }
    Fraction operator * (const Fraction& f) {
        Fraction a = Fraction(num, f.den);
        Fraction b = Fraction(f.num, den);
        return Fraction(a.num * b.num, a.den * b.den);
    }
    Fraction operator / (const Fraction& f) {
        return *this * Fraction(f.den, f.num);
    }
    Fraction operator += (const Fraction& f) { return *this = *this + f; }
    Fraction operator -= (const Fraction& f) { return *this = *this - f; }
    Fraction operator *= (const Fraction& f) { return *this = *this * f; }
    Fraction operator /= (const Fraction& f) { return *this = *this / f; }
    bool operator == (const Fraction& f) const { return compare(f) == 0; }
    bool operator != (const Fraction& f) const { return compare(f) != 0; }
    bool operator >= (const Fraction& f) const { return compare(f) >= 0; }
    bool operator <= (const Fraction& f) const { return compare(f) <= 0; }
    bool operator > (const Fraction& f) const { return compare(f) > 0; }
    bool operator < (const Fraction& f) const { return compare(f) < 0; }
};
Fraction operator - (const Fraction& f) { return Fraction(-f.num, f.den); }
ostream& operator << (ostream& os, const Fraction& f) {
    return os << "(" << (ll)f.num << "/" << (ll)f.den << ")";
}
