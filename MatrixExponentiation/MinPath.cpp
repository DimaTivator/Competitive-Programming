// https://codeforces.com/gym/102644/problem/F

const int MOD = 1e9 + 7;
const int LLINF = 3e18 + 7;
const int INF = 2e9 + 7;
const int N = 2e5 + 13;
const ld eps = 0.00000001;

int n = 110;

struct Matrix {
    vector <vector <int> > a = vector <vector <int>>(n, vector <int> (n, LLINF));

    Matrix operator *(Matrix other) {
        Matrix res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res.a[i][k] = min(res.a[i][k], a[i][j] + other.a[j][k]);
                }
            }
        }
        return res;
    }
};

Matrix exp_pow(Matrix a, int b) {
    Matrix product;
    for (int i = 0; i < n; i++) product.a[i][i] = 0;
    while (b > 0) {
        if (b % 2 == 1) {
            product = product * a;
        }
        a = a * a;
        b /= 2;
    }
    return product;
}



void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    Matrix a;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        a.a[x - 1][y - 1] = w;
    }
    Matrix res = exp_pow(a, k);
    int ans = LLINF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = min(ans, res.a[i][j]);
        }
    }
    if (ans >= 1e18L + 5) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << ans << endl;
    }
}

