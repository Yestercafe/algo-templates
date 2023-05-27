struct Dsu {
    std::vector<size_t> pa, size, sum;

    explicit Dsu(size_t size_)
        : pa(size_ * 2), size(size_ * 2, 1), sum(size_ * 2) {
            std::iota(pa.begin(), pa.begin() + size_, size_);
            std::iota(pa.begin() + size_, pa.end(), size_);
            std::iota(sum.begin() + size_, sum.end(), 0);
        }

    void unite(size_t x, size_t y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) std::swap(x, y);
        pa[y] = x;
        size[x] += size[y];
        sum[x] += sum[y];
    }

    void move(size_t x, size_t y) {
        auto fx = find(x), fy = find(y);
        if (fx == fy) return;
        pa[x] = fy;
        --size[fx], ++size[fy];
        sum[fx] -= x, sum[fy] += x;
    }

    size_t find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
};

