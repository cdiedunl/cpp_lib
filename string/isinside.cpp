// isInside(a, b) returns true if a contains b, else false.

bool isInside(const string &s, const string &f) {
    return !(kmp(s, f).size()) ? 0 : 1;
}
