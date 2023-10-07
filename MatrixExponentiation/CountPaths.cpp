// This code counts the number of paths with length k in the directed grapth 
// https://codeforces.com/gym/102644/problem/D

int n;

struct Matrix {
    vector <vector <int> > a = vector <vector <int>>(n, vector <int> (n, 0));

    Matrix operator *(Matrix other) {
        Matrix res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res.a[i][k] = (res.a[i][k] + a[i][j] * other.a[j][k]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix exp_pow(Matrix a, int b) {
    Matrix product;
    for (int i = 0; i < n; i++) product.a[i][i] = 1;
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
    int m, k;
    cin >> n >> m >> k;
    Matrix adj_matrix;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj_matrix.a[a][b]++;
    }
    Matrix cnt_paths = exp_pow(adj_matrix, k);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += cnt_paths.a[i][j];
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

