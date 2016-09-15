Range minimum query. Recibe como parametro en el constructor un array de valores. Las consultas se realizan con el método rmq(indice_inicio, indice_final) y pueden actualizarse los valores con update_point(indice, nuevo_valor)

import java.util.*;

class SegmentTree {        
  private int[] st, A;
  private int n;
  private int left (int p) { return p << 1; }
  private int right(int p) { return (p << 1) + 1; }

  private void build(int p, int L, int R) {
    if (L == R) 
      st[p] = L;
    else { 
      build(left(p) , L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    } 
  }

  private int rmq(int p, int L, int R, int i, int j) {
    if (i >  R || j <  L) return -1;
    if (L >= i && R <= j) return st[p];
    int p1 = rmq(left(p) , L, (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;  
    if (p2 == -1) return p1;
    return (A[p1] <= A[p2]) ? p1 : p2; } 

  private int update_point(int p, int L, int R, int idx, int new_value) {
    int i = idx, j = idx;
    if (i > R || j < L)
      return st[p];
    if (L == i && R == j) {
      A[i] = new_value; 
      return st[p] = L; 
    }
    int p1, p2;
    p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);

    return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }

  public SegmentTree(int[] _A) {
    A = _A; n = A.length; 
    st = new int[4 * n];
    for (int i = 0; i < 4 * n; i++) st[i] = 0;
    build(1, 0, n - 1); 
  }

  public int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } 
  public int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
}

class Main {
  public static void main(String[] args) {
    int[] A = new int[] { 18, 17, 13, 19, 15, 11, 20 };
    SegmentTree st = new SegmentTree(A);
  }
}
