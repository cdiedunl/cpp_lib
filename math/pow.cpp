ull pow(ull base, ull power, ull mod) {
    ull res = 1;
    while (power) {
        if (power & 1) res = ((__int128)res * base % mod);
        power >>= 1, base = ((__int128)base * base % mod);
    }
    return res;
}
