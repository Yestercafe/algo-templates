// https://github.com/Yescafe/leetcode-solutions/blob/master/weekly/349/q4_a_rmq-solution.cc
class STMax {
    struct Node {
        int l, r;
        int val;
        Node *left, *right;
        Node(int l, int r) : l{l}, r{r} {
            val = -1;
            left = right = nullptr;
        }
        ~Node() {
            if (left) delete left;
            if (right) delete right;
        }
        void lift() {
            if (left) val = max(val, left->val);
            if (right) val = max(val, right->val);
        }
        void update(int pos, int val) {
            if (l != r) {
                auto m = l + r >> 1;
                // [l, m], [m + 1, r]
                if (pos <= m) {   // fall in left
                    if (!this->left) this->left = new Node(l, m);
                    this->left->update(pos, val);
                } else {          // fall in right
                    if (!this->right) this->right = new Node(m + 1, r);
                    this->right->update(pos, val);
                }
                this->lift();
            } else {
                this->val = max(this->val, val);
            }
        }
        int rangeQuery(int ql, int qr) {
            if (l == ql && r == qr) {
                return val;
            }
            int m = l + r >> 1;
            int ret = -1;
            if (qr <= m) {
                if (left) ret = max(ret, left->rangeQuery(left->l, qr));
            } else if (m < ql) {
                if (right) ret = max(ret, right->rangeQuery(ql, right->r));
            } else {
                if (left) ret = max(ret, left->rangeQuery(ql, m));
                if (right) ret = max(ret, right->rangeQuery(m + 1, qr));
            }
            
            return ret;
        }
    };

    Node* root;
public:
    STMax(int l, int r) {
        root = new Node(l, r);
    }
    ~STMax() {
        delete root;
    }
    void modify(int pos, int val) {
        root->update(pos, val);
    }
    int rangeQuery(int ql, int qr) {
        return root->rangeQuery(ql, qr);
    }
};

