#include <bits/stdc++.h>
#include "../Numeric.ipp"

int main() {
    constexpr int P = 1e9 + 7;

    M32<P> a(10000), b(1000000);
    std::cout << power(a, b.get()) << std::endl;
    std::cout << a / b << std::endl;

    M64<P> a64(10000), b64(1000000);
    std::cout << power(a64, b64.get()) << std::endl;
    std::cout << a64 / b64 << std::endl;

    M32<6> c(70), d(7);
    std::cout << c / d << std::endl;

    return 0;
}

