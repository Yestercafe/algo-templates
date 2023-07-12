struct Dsu {
    std::size_t n;
    std::vector<size_t> pa, size;

    explicit Dsu(size_t n)
      : n{n}, pa(n), size(n, 1) {
        std::iota(pa.begin(), pa.end(), 0);
    }

    void unite(size_t x, size_t y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) std::swap(x, y);
        pa[y] = x;
        size[x] += size[y];
    }

    size_t find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
};

