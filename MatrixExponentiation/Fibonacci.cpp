// Computation of n-th fibonacci sequence element 
// by matrix exponentiation. Time complexity O(log(n))
// https://codeforces.com/gym/102644/problem/C

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
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    Matrix m;
    m.a[0][0] = 0;
    m.a[1][0] = 1;
    m.a[1][1] = 1;
    m.a[0][1] = 1;
    Matrix res = exp_pow(m, n - 1);
    cout << res.a[1][1] << endl;
}


