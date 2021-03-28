typedef double lf;
const lf eps = 1e-9;
typedef double T;
struct pt {
    T x, y;
    pt operator + (pt p) { return {x+p.x, y+p.y}; }
    pt operator - (pt p) { return {x-p.x, y-p.y}; }
    pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
    pt operator * (T d) { return {x*d, y*d}; }
    pt operator / (lf d) { return {x/d, y/d}; } /// only for floating point
    bool operator == (pt b) { return x == b.x && y == b.y; }
    bool operator != (pt b) { return !(*this == b); }
    bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
    bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};
int cmp (lf a, lf b) { return (a + eps < b ? -1 :(b + eps < a ? 1 : 0)); } //double comparator

T norm(pt a) { return a.x*a.x + a.y*a.y; }
lf abs(pt a) { return sqrt(norm(a)); }
lf arg(pt a) { return atan2(a.y, a.x); }
pt unit(pt a) { return a/abs(a); }

T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; } // x = 90 -> cos = 0
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; } // x = 180 -> sin = 0
T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }// clockwise = -
pt rot(pt p, lf a) { return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)}; }
pt rotate_to_b(pt a, pt b, lf ang) { return rot(a-b, ang)+b; } // rotate by ang center b
pt rot90ccw(pt p) { return {-p.y, p.x}; }
pt rot90cw(pt p) { return {p.y, -p.x}; }
pt translate(pt p, pt v) { return p+v; }
pt scale(pt p, double f, pt c) { return c + (p-c)*f; } // c-center
bool are_perp(pt v, pt w) { return dot(v,w) == 0; }
int sign(T x) { return (T(0) < x) - (x < T(0)); }

bool in_angle(pt a, pt b, pt c, pt x) { // x inside angle abc (center in a)
    assert(orient(a,b,c) != 0);
    if (orient(a,b,c) < 0) swap(b,c);
    return orient(a,b,x) >= 0 && orient(a,c,x) <= 0;
}
//angle bwn 2 vectors
lf angle(pt a, pt b) { return acos(max(-1.0, min(1.0, dot(a,b)/abs(a)/abs(b)))); }
lf angle(pt a, pt b) { return atan2(cross(a, b), dot(a, b)); }
/// returns vector to transform points
pt get_linear_transformation(pt p, pt q, pt r, pt fp, pt fq) {
    pt pq = q-p, num{cross(pq, fq-fp), dot(pq, fq-fp)};
    return fp + pt{cross(r-p, num), dot(r-p, num)} / norm(pq);
}
bool half(pt p) { /// true if is in (0, 180] (line is x axis)
    assert(p.x != 0 || p.y != 0); /// the argument of (0,0) is undefined
    return p.y > 0 || (p.y == 0 && p.x < 0);
}
bool half_from(pt p, pt v = {1, 0}) { //line is v (above v is true)
    return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) < 0);
}
bool polar_cmp(const pt &a, const pt &b) {//polar sort
    return make_tuple(half(a), 0) < make_tuple(half(b), cross(a,b));
//   return make_tuple(half(a), 0, sq(a)) < make_tuple(half(b), cross(a, b), sq(b)); // further ones appear later
}
