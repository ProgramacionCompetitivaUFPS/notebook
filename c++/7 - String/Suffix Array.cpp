const int MAXL = 300;

struct suffixArray {
    string s;
    int n, MX;
    vector<int> ra, tra, sa, tsa, lcp;

    suffixArray(string &_s) {
        s = _s+"$";
        n = s.size();
        MX = max(MAXL, n)+2;
        ra = tra = sa = tsa = lcp = vector<int>(n);
        build();
    }

    void radix_sort(int k) {
        vector<int> cnt(MX, 0);
        for(int i = 0; i < n; i++)
            cnt[(i+k < n) ? ra[i+k]+1 : 1]++;
        for(int i = 1; i < MX; i++)
            cnt[i] += cnt[i-1];
        for(int i = 0; i < n; i++)
            tsa[cnt[(sa[i]+k < n) ? ra[sa[i]+k] : 0]++] = sa[i];
        sa = tsa;
    }

    void build() {
        for (int i = 0; i < n; i++)
            ra[i] = s[i], sa[i] = i;
        for (int k = 1, r; k < n; k <<= 1) {
            radix_sort(k);
            radix_sort(0);
            tra[sa[0]] = r = 0;
            for (int i = 1; i < n; i++) {
                if (ra[sa[i]] != ra[sa[i-1]] || ra[sa[i]+k] != ra[sa[i-1]+k]) ++r;
                tra[sa[i]] = r;
            }
            ra = tra;
            if (ra[sa[n-1]] == n-1) break;
        }
    }

    int& operator[] (int i) { return sa[i]; }

    void build_lcp() {
        lcp[0] = 0;
        for (int i = 0, k = 0; i < n; i++) {
            if (!ra[i]) continue;
            while (s[i+k] == s[sa[ra[i]-1]+k]) k++;
            lcp[ra[i]] = k;
            if (k) k--;
        }
    }
    //Longest Common Substring: construir el suffixArray s = s1 + "#" + s2 + "$" y m = s2.size()
    pair<int, int> lcs() {
        int mx = -1, ind = -1;
        for (int i = 1; i < n; i++) {
            if (((sa[i] < n-m-1) != (sa[i-1] < n-m-1)) && mx < lcp[i]) {
                mx = lcp[i]; ind = i;
            }
        }
        return {mx, ind};
    }
};
