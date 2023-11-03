// Given an array and q queries: l r x - add x on [l; r]
// Output the array after all queries
//
// We use difference array `d` here to simplify add on segment operation 
// After all operations the answer is the array of preffix sums of `d` (just check what we get
// if we compute preffix sums of difference array) 

vector <int> d, p;

void build_diff(vector <int>& a) {
    d.resize(sz(a));
    d[0] = a[0];
    for (int i = 1; i < sz(a); i++) {
        d[i] = a[i] - a[i - 1];
    }
}

void build_pref(vector <int>& a) {
    p.resize(sz(a) + 1);
    for (int i = 1; i <= sz(a); i++) {
        p[i] = a[i - 1] + p[i - 1];
    }
}

void update(int l, int r, int x) {
    d[l] += x;
    d[r + 1] -= x;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    build_diff(a);
    
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        update(l, r, x);    
    }
    
    build_pref(d);

    for (int i = 1; i <= n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
}

