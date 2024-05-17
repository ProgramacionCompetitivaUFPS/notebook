Problemas clásicos de moneda con DP

const int MAX_COINS = 1005;
const int MAX_VALUE = 1005;
const int INF = (int) (2e9);
int coins[MAX_COINS];
int dp[MAX_VALUE];
vector<int> rb;

// Calcula el número de formas para valores entre 1 y value. SIN CONTAR PERMUTACIONES
void ways(int value) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (auto c: coins) {
        for (int i = 1; i <= value; i++) {
            if (i - c >= 0) dp[i] += dp[i - c];
        }
    }
}

// Calcula el número de formas para valores entre 1 y value. CONTANDO PERMUTACIONES
void ways_perm(int value) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= value; i++) {
        for (auto c: coins) {
            if (i - c >= 0) dp[i] += dp[i - c];
        }
    }
}

// Calcula el minimo numero de monedas necesarias para los valores entre 1 y value.
void min_coin(int value) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= value; i++) {
        dp[i] = INF;
        for (auto c: coins) {
            if (i - c >= 0) dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
}

// Guarda en el vector rb las monedas usadas en min_coin.
void build_ways(int value) {
    rb.clear();
    for (int c = MAX_COINS - 1; c >= 0; c--) {
        if (value == 0) return;
        while (value - coins[c] >= 0 && dp[value] == dp[value - coins[c]] + 1) {
            rb.push_back(coins[c]);
            value -= coins[c];
        }
    }
}
