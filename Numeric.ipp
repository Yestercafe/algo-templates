using i64 = long long;

template<typename T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;}

i64 mulmod(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template<int Mod>
struct M32 {
    int nu;
    M32() : nu{0} {}
    M32(int nu) : nu{nu} {
        clamp();
    }
    friend std::ostream& operator<<(std::ostream& os, const M32& rhs) {
        return (os << rhs.nu);
    }
    friend std::istream& operator>>(std::istream& is, M32& rhs) {
        return (is >> rhs.nu);
    }
    M32& clamp() {
        if (nu < 0) nu += Mod;
        nu %= Mod;
        return *this;
    }
    int get() {
        nu %= Mod;
        return nu;
    }
    
    M32& operator+=(const M32& rhs) {
        nu += rhs.nu;
        clamp();
        return *this;
    }
    M32& operator-=(const M32& rhs) {
        nu -= rhs.nu;
        clamp();
        return *this;
    }
    M32& operator*=(const M32& rhs) {
        nu = mulmod(nu, rhs.nu, Mod);
        return *this;
    }
    M32& operator/=(const M32& rhs) {
        return *this *= rhs.inv();
    }
    
    M32 operator+(const M32& rhs) {
        M32 lhs = *this;
        return lhs += rhs;
    }
    M32 operator-(const M32& rhs) {
        M32 lhs = *this;
        return lhs -= rhs;
    }
    M32 operator*(const M32& rhs) {
        M32 lhs = *this;
        return lhs *= rhs;
    }
    M32 operator/(const M32& rhs) {
        M32 lhs = *this;
        return lhs /= rhs;
    }

    friend bool operator==(const M32& lhs, const M32& rhs) {
        return lhs.get() == rhs.get();
    }
    friend bool operator!=(const M32& lhs, const M32& rhs) {
        return !(lhs == rhs);
    }

    M32 inv() const {
        assert(nu != 0);
        return power(*this, Mod - 2);
    }
};

template<i64 Mod>
struct M64 {
    i64 nu;
    M64() : nu{0} {}
    M64(i64 nu) : nu{nu} {
        clamp();
    }
    friend std::ostream& operator<<(std::ostream& os, const M64& rhs) {
        return (os << rhs.nu);
    }
    friend std::istream& operator>>(std::istream& is, M64& rhs) {
        return (is >> rhs.nu);
    }
    M64& clamp() {
        if (nu < 0) nu += Mod;
        nu %= Mod;
        return *this;
    }
    i64 get() {
        nu %= Mod;
        return nu;
    }
    
    M64& operator+=(const M64& rhs) {
        nu += rhs.nu;
        clamp();
        return *this;
    }
    M64& operator-=(const M64& rhs) {
        nu -= rhs.nu;
        clamp();
        return *this;
    }
    M64& operator*=(const M64& rhs) {
        nu = mulmod(nu, rhs.nu, Mod);
        return *this;
    }
    M64& operator/=(const M64& rhs) {
        return *this *= rhs.inv();
    }
    
    M64 operator+(const M64& rhs) {
        M64 lhs = *this;
        return lhs += rhs;
    }
    M64 operator-(const M64& rhs) {
        M64 lhs = *this;
        return lhs -= rhs;
    }
    M64 operator*(const M64& rhs) {
        M64 lhs = *this;
        return lhs *= rhs;
    }
    M64 operator/(const M64& rhs) {
        M64 lhs = *this;
        return lhs /= rhs;
    }

    friend bool operator==(const M64& lhs, const M64& rhs) {
        return lhs.get() == rhs.get();
    }
    friend bool operator!=(const M64& lhs, const M64& rhs) {
        return !(lhs == rhs);
    }

    M64 inv() const {
        assert(nu != 0);
        return power(*this, Mod - 2);
    }
};

