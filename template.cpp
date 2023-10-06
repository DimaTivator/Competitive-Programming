#ifndef ONPC
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define fi first
#define sec second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pld pair<long double, long double>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define endl "\n"

template<typename T> void __print(T x) { cerr << x; }
template<typename T, typename V> void __print(pair<T, V> x) { cerr << "{"; __print(x.first); cerr << ", "; __print(x.second); cerr << "}"; }
template<typename T> void __print(vector<T> x) { cerr << "[ "; for (auto it = x.begin(); it != x.end(); ++it) { if (it != x.begin()) cerr << ", "; __print(*it); } cerr << " ]"; }
template<typename T> void __print(set<T> x) { cerr << "[ "; for (auto it = x.begin(); it != x.end(); ++it) { if (it != x.begin()) cerr << ", "; __print(*it); } cerr << " ]"; }

void debug_out() {
    cerr << endl;
}

template<typename H, typename... T>
void debug_out(H h, T... t) {
    cerr << " ";
    __print(h);
    debug_out(t...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int MOD = 1e9 + 7;
const int LLINF = 2e18 + 7;
const int INF = 2e9 + 7;
const int N = 2e5 + 13;
const ld eps = 0.00000001;

void solve() {

}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(15);
    #ifdef ONPC
        cout << "\n";
    #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        #ifdef ONPC
           cout << "________________________\n";
        #endif
    }
     
    return 0;
}
