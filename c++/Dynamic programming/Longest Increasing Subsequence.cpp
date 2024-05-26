// METODO PARA CALCULAR EL LIS en O(n^2) y O(nlog(n)). La ventaja de tener a mano O(n^2) es porque es mas facil de codear, entender y modificar

const int MAX = 1e5+1;
int A[MAX];
int dp[MAX];
int N = MAX;
vector<int> LIS; // PARA Lis_opt

// LIS O(n^2).Si es non-decreasing cambiar (i > j) por (i >= j)
int lis() {
    int best = -1;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        best = max(best, dp[i]);
    }
    return best;
}

// LIS O(nlog(n)) Para longest non-decreasing cambiar lower_bound por upper_bound
int lis_opt() {
    LIS.clear();
    for (int i = 0; i < N; i++) {
        auto id = lower_bound(LIS.begin(), LIS.end(), A[i]);
        if (id == LIS.end()) {
            LIS.push_back(A[i]);
            dp[i] = LIS.size();
        }
        else {
            int idx = id - LIS.begin();
            LIS[idx] = A[i];
            dp[i] = idx + 1;
        }
    }
    return LIS.size();
}

// METODO PARA RECONSTRUIR LIS. Para non-decreasing cambiar < por <=
stack<int> rb;
void build() {
    int k = LIS.size();
    int cur = oo;
    for (int i = N - 1; i >= 0, k; i--) {
        if (A[i] < cur && k == dp[i]) {
            cur = A[i];
            rb.push(A[i]);
            k--;
        }
    }
}
