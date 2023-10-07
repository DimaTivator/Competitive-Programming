// https://codeforces.com/gym/102644/problem/E

struct Matrix {
    vector <vector <unsigned int> > a = vector <vector <unsigned int>>(A, vector <unsigned int> (A, 0));

    Matrix operator *(Matrix other) {
        Matrix res;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < A; j++) {
                for (int k = 0; k < A; k++) {
                    res.a[i][k] += a[i][j] * other.a[j][k];
                }
            }
        }
        return res;
    }
};

Matrix exp_pow(Matrix a, int b) {
    Matrix product;
    for (int i = 0; i < A; i++) product.a[i][i] = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            product = product * a;
        }
        a = a * a;
        b /= 2;
    }
    return product;
}

bool in_grid(int i, int j) {
    return i >= 0 && i <= 7 && j >= 0 && j <= 7;
}

void solve() {
    int k;
    cin >> k;
    
    Matrix board;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int di : {-2, -1, 1, 2}) {
                for (int dj : {-2, -1, 1, 2}) {
                    if (abs(di) != abs(dj) && in_grid(i + di, j + dj)) {
                        board.a[8 * i + j][8 * (i + di) + j + dj] = 1;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < A; i++) {
        board.a[i][64] = 1;
    }
    
    Matrix res = exp_pow(board, k + 1);

    cout << res.a[0][64] << endl; // a[0][64] - the number of ways from the top-left corner to the cell, representing the answer
}


