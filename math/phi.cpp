ull phi(ull n) {
    ull res = n;
    for (ull i = 2; i*i <= n; i++)
        if (!(n % i)) {
            res -= (res / i);
            while (!(n % i)) n /= i;
        }
    return (n > 1 ? res - (res / n) : res);
}
