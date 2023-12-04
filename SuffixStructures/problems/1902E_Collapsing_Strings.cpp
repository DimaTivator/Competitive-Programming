// https://codeforces.com/contest/1902/problem/E?locale=ru

int full = 0;
int n = 0;

struct Node {
    map <char, Node*> to;
    int en = 0;
    int cnt = 0;
};

class Trie {
    private:
        Node* root;

    public:

        Trie() : root(new Node()) {}

        void insert(const string& s) {
            Node* cur = root;
            for (char c : s) {
                if (cur->to.find(c) == cur->to.end()) {
                    cur->to[c] = new Node();
                }
                cur = cur->to[c];
                cur->cnt++;
            }
            cur->en++;
        }

        int get(const string& s) {
            Node* cur = root;
            int res = full + n * sz(s);
            int k = 1;
            for (char c : s) {
                cur = cur->to[c];
                if (cur == NULL) {
                    break;
                }
                res -= 2 * cur->cnt;
                k++;
            }
            return res;
        }
};

void solve() {
    cin >> n;
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        full += sz(a[i]);
    }

    Trie t1;

    for (int i = 0; i < n; i++) {
        t1.insert(a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string t = a[i];
        reverse(all(t));
        ans += t1.get(t);
        debug(t, t1.get(t));
    }

    cout << ans << endl;
}

