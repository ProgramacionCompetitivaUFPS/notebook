import java.util.*;

class SegmentTree {        
  private int[] st, A;
  private int n;
  private int left (int p) { return p << 1; }
  private int right(int p) { return (p << 1) + 1; }

  private void build(int p, int L, int R) {
    if (L == R)                            // as L == R, either one is fine
      st[p] = L;                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    } 
  }

  private int rmq(int p, int L, int R, int i, int j) {          // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    int p1 = rmq(left(p) , L, (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;                               // same as above
    return (A[p1] <= A[p2]) ? p1 : p2; }          // as as in build routine

  private int update_point(int p, int L, int R, int idx, int new_value) {
    int i = idx, j = idx;

    // if the current interval does not intersect 
    // the update interval, return this st node value!
    if (i > R || j < L)
      return st[p];

    // if the current interval is included in the update range,
    // update that st[node]
    if (L == i && R == j) {
      A[i] = new_value; // update the underlying array
      return st[p] = L; // this index
    }

    // compute the minimum position in the 
    // left and right part of the interval
    int p1, p2;
    p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

    // return the position where the overall minimum is
    return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }

  public SegmentTree(int[] _A) {
    A = _A; n = A.length;                   // copy content for local usage
    st = new int[4 * n];
    for (int i = 0; i < 4 * n; i++) st[i] = 0; // create vector with length `len' and fill it with zeroes
    build(1, 0, n - 1);                                  // recursive build
  }

  public int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading

  public int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
}

class Main {
  public static void main(String[] args) {
    int[] A = new int[] { 18, 17, 13, 19, 15, 11, 20 }; // the original array
    SegmentTree st = new SegmentTree(A);
  }
}
