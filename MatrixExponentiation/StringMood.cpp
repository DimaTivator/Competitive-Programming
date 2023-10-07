https://codeforces.com/gym/102644/problem/B

struct Matrix {
    int a[2][2] = {{0, 0}, {0, 0}};

    Matrix operator *(Matrix other) {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.a[i][k] = (res.a[i][k] + a[i][j] * other.a[j][k]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix exp_pow(Matrix a, int b) {
    Matrix product;
    for (int i = 0; i < 2; i++) product.a[i][i] = 1;
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
    int n;
    cin >> n;
    Matrix m;
    m.a[0][0] = 19;
    m.a[1][0] = 6;
    m.a[0][1] = 7;
    m.a[1][1] = 20;
    Matrix res = exp_pow(m, n);
    cout << res.a[0][0] << endl;
}
