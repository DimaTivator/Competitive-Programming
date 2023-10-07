https://codeforces.com/gym/102644/problem/A

struct Matrix {
    ld a[2][2] = {{0, 0}, {0, 0}};

    Matrix operator *(Matrix other) {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.a[i][k] = res.a[i][k] + a[i][j] * other.a[j][k];
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
    ld p;
    cin >> n >> p;
    Matrix m;
    m.a[0][0] = 1 - p;
    m.a[0][1] = p;
    m.a[1][0] = p;
    m.a[1][1] = 1 - p;
    Matrix product = exp_pow(m, n);
    cout << product.a[0][0] << endl;
}

