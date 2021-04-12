bool isPrime(ull n) {
    if (n < 2) return 0;
    if (n != 2 && n % 2 == 0) return 0;
    auto f = [&](ull n, ull a) {
        if (a % n == 0) return 1;
        ull k = n-1;
        while (1) {
            ull tmp = pow(a, k, n);
            if (tmp == n-1) return 1;
            if (k % 2) return (int)(tmp==1 || tmp==n-1);
            k /= 2;
        }
    }; int base[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (auto &i: base) if (!f(n, i)) return 0;
    return 1;
}
