// returns all start index of s where f is. index is 0-based.

vector<ull> kmp(const string &s, const string &f) {
    auto x = [&](const string &s) {
        ull m = s.size(), be = 1, mat = 0;
        vector<ull> res(m, 0);
        while (be+mat < m) {
            if (s[be+mat] == s[mat]) mat++, res[be+mat-1] = mat;
            else if (!mat) be++;
            else be += mat - res[mat-1], mat = res[mat-1];
        } return res;
    };
    ull n = s.size(), m = f.size(), mat = 0, i;
    vector<ull> res, pi = x(f);
    for (i = 0; i < n; i++) {
        while (mat > 0 && s[i] != f[mat]) mat = pi[mat-1];
        if (s[i] == f[mat]) if (++mat == m) res.pb(i-m+1), mat = pi[mat-1];
    }
    return res;
}
