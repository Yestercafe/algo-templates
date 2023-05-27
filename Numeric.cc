using i64 = long long;

i64 powmod(i64 a, i64 b, i64 p) {
    i64 ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

