template <typename T, typename Sum = T>
class DstBitNot {
    std::vector<T> tree;
    std::vector<bool> lazy;
    std::vector<T> *arr;
    int n, root, n4, end;

    void pushdown(int cl, int cr, int p) {
        if (lazy[p]) {
            int cm = cl + (cr - cl) / 2;
            lazy[p * 2] = !lazy[p * 2];
            lazy[p * 2 + 1] = !lazy[p * 2 + 1];
            tree[p * 2] = (cm - cl + 1) - tree[p * 2];
            tree[p * 2 + 1] = (cr - cm) - tree[p * 2 + 1];
            lazy[p] = false;
        }
    }

    Sum range_sum(int l, int r, int cl, int cr, int p) {
        if (l <= cl && cr <= r) return tree[p];
        pushdown(cl, cr, p);
        int m = cl + (cr - cl) / 2;
        Sum sum = 0;
        if (l <= m) sum += range_sum(l, r, cl, m, p * 2);
        if (r > m) sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
        return sum;
    }

    void range_not(int l, int r, int cl, int cr, int p) {
        if (l <= cl && cr <= r) {
            lazy[p] = !lazy[p];
            tree[p] = (cr - cl + 1) - tree[p];
            return;
        }
        pushdown(cl, cr, p);
        int m = cl + (cr - cl) / 2;
        if (l <= m) range_not(l, r, cl, m, p * 2);
        if (r > m) range_not(l, r, m + 1, cr, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    void build(int s, int t, int p) {
        if (s == t) {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

public:
    explicit DstBitNot(std::size_t n) {
        this->n = n;
        n4 = n * 4;
        tree = std::vector<T>(n4, 0);
        lazy = std::vector<bool>(n4, false);
        end = n - 1;
        root = 1;
    }

    explicit DstBitNot(std::vector<T>& v) {
        n = v.size();
        n4 = n * 4;
        tree = std::vector<T>(n4, 0);
        lazy = std::vector<bool>(n4, false);
        arr = &v;
        end = n - 1;
        root = 1;
        build(0, end, 1);
        arr = nullptr;
    }

    void show(int p, int depth = 0) {
        if (p > n4 || tree[p] == 0) return;
        show(p * 2, depth + 1);
        for (int i = 0; i < depth; ++i) std::putchar('\t');
        std::printf("%d:%d\n", tree[p], lazy[p]);
        show(p * 2 + 1, depth + 1);
    }

    Sum bit_count(int l, int r) { return range_sum(l, r, 0, end, root); }

    void range_not(int l, int r) { range_not(l, r, 0, end, root); }
};
