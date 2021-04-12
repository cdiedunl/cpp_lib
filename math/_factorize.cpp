void pld(ull n, vector<ull> &v) {
    if (n == 1) return;
    if (n % 2 == 0) { v.pb(2); pld(n/2, v); return; }
    if (isPrime(n)) { v.pb(n); return; }
    auto f = [&](ull x, ull n, ull c) { 
        return (c + ((__int128)x * x % n)) % n; 
    }; ull a, b, c;
    while (1) {
        a = b = rand() % (n-2) + 2, c = rand() % 20 + 1;
        do a = f(a, n, c), b = f(f(b, n, c), n, c); 
        while (gcd(abs((ll)(a-b)), n) == 1);
        if (a != b) break;
    }
    ull g = gcd(abs((ll)(a-b)), n);
    pld(g, v); pld(n/g, v);
}

vector<ull> factorize(ull n) {
    vector<ull> res;
    pld(n, res); sort(all(res));
    return res;
}
