#include <bits/stdc++.h>
#include "../DSU.ipp"

int main() {
    int n = 5;
    Dsu dsu(n);

    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(3, 4);

    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(dsu.find(i));
    }

    std::cout << s.size() << std::endl;

    return 0;
}

