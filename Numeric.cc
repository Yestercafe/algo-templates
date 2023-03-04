typedef long long ll;

ll powmod(ll a, ll b, ll p) {
    ll ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

