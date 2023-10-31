// https://codeforces.com/gym/104614/problem/L
// To solve this problem we should make the matrix c: c[i][j] - the cost of assigning product j to warehouse i
// Then we apply a basic hungarian algorithm to matrix c
// hungarian algorithm: https://e-maxx.ru/algo/assignment_hungary
// 
// Also in this problem we enumerate all things from 1

#define FOR(i, f) for (int i = 1; i < (f); i++)

int hungarian(vector <vector <int>>& a) {
    int n = sz(a) - 1, m = sz(a) - 1;
    vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
    for (int i=1; i<=n; ++i) {
	    p[0] = i;
	    int j0 = 0;
	    vector<int> minv (m+1, INF);
	    vector<char> used (m+1, false);
	    do {
		    used[j0] = true;
		    int i0 = p[j0],  delta = INF,  j1;
		    for (int j=1; j<=m; ++j) {
			    if (!used[j]) {
				    int cur = a[i0][j]-u[i0]-v[j];
				    if (cur < minv[j])
					    minv[j] = cur,  way[j] = j0;
				    if (minv[j] < delta)
					    delta = minv[j],  j1 = j;
			    }
            }
		    for (int j=0; j<=m; ++j) {
			    if (used[j])
				    u[p[j]] += delta,  v[j] -= delta;
			    else
			    	minv[j] -= delta;
            }
		    j0 = j1;
	    } while (p[j0] != 0);
	    do {
		    int j1 = way[j0];
		    p[j0] = p[j1];
		    j0 = j1;
	    } while (j0);
    }
    int ans = 0;
    for (int j=1; j<=m; ++j) {
        ans += a[p[j]][j];
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    n++;
    m++;
    vector <vector <int>> p(n, vector <int> (m));
    FOR(i, n) {
        FOR(j, m) {
            cin >> p[i][j];
        }
    }
    vector <vector <int>> d(n, vector <int> (n));
    FOR(i, n) {
        FOR(j, n) {
            cin >> d[i][j];
            if (d[i][j] == -1) {
                d[i][j] = INF;
            }
        }
    }
    FOR(k, n) {
        FOR(i, n) {
            FOR(j, n) {
                if (d[i][k] < INF && d[k][j] < INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    vector <vector <int>> c(n, vector <int> (n));
    FOR(i, n) {
        FOR(j, m) {
            FOR(k, n) {
                c[i][j] += d[k][i] * p[k][j];
            }
        }
    }
    FOR(i, n) {
        FOR(j, i) {
            swap(c[i][j], c[j][i]);
        }
    }
    cout << hungarian(c) << endl;
}

