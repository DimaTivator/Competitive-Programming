long long gcd(long long a, long long b) {
    while (b != 0) {
        long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector <long long> a(n);
    for (long long& i : a) {
        cin >> i;
    }
    
    srand(time(NULL));
    
    vector <long long> d;
    map <long long, int> m;
    vector <int> cnt;

    long long ans = 0;
    for (int k = 0; k < 14; k++) {
        int x = a[((long long)(rand() * rand())) % n];
        m.clear();
        for (int i = 0; i < n; i++) {
            m[gcd(x, a[i])]++;
        }
        d.clear();
        cnt.clear();
        for (map<long long, int>::iterator it = m.begin(); it != m.end(); it++) {
            d.push_back(it->fi);
            cnt.push_back(it->sec);
        }
        for (int i = 0; i < sz(d); i++) {
            int cur = 0;
            for (int j = i; j < sz(d); j++) {
                if (d[j] % d[i] == 0) {
                    cur += cnt[j];
                }
            }
            if (2 * cur >= n) {
                ans = max(ans, d[i]);
            }
        }
    }

    cout << ans << endl;
}
