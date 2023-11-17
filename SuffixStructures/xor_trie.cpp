// given an array a
// and q numbers x_1, x_2, ..., x_q
// for every x_i output maximum and minimum value of x_i ^ a[j] for all j \in { 0..n-1 }
    
// here's a possible solution 
// it's explanation is in xor_trie.pdf 

// this idea is used in https://codeforces.com/problemset/problem/1895/D (we need only get_max function in this problem)

const int LOG = 20;

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector <vector <int>> t;
    t.push_back({ -1, -1 });

    auto insert = [&](int x) {
        int v = 0;
        for (int i = LOG; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (t[v][j] == -1) {
                t[v][j] = sz(t);
                t.push_back({ -1, -1 });
            }
            v = t[v][j];
        }
    };

    auto get_max = [&](int x) {
        int v = 0;
        for (int i = LOG; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (t[v][j ^ 1] != -1) {
                j ^= 1;
            }
            x ^= (j << i);
            v = t[v][j];
        }
        return x;
    };

    auto get_min = [&](int x) {
        int v = 0;
        for (int i = LOG; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (t[v][j] == -1) {
                j ^= 1;
            }
            x ^= (j << i);
            v = t[v][j];
        }
        return x;
    };
    
    for (int i = 0; i < n; i++) {
        insert(a[i]);
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << get_max(x) << ' ' << get_min(x) <<  endl;
    }
} 


