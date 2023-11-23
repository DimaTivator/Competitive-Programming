#ifdef ONPC
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


#ifdef ONPC
    #include "algo/debug.h"
#else
    #define debug(...) 42
#endif

const int MOD = 1e9 + 7;
const int LLINF = 2e18 + 7;
const int INF = 2e9 + 7;
const int N = 2e5 + 13;
const ld eps = 0.00000001;


struct P {
    int x, y;
    
    void read() {
        cin >> x >> y;
    }
    
    P operator - (const P& b) const {
        return P{ x - b.x, y - b.y };
    }

    P operator + (const P& b) const {
        return P{ x + b.x, y + b.y };
    }

    void operator -= (const P& b) {
        x -= b.x;
        y -= b.y;
    }

    void operator += (const P& b) {
        x += b.x;
        y += b.y;
    }

    int operator * (const P& b) const {
        return x * b.y - b.x * y;
    }

    bool operator<(const P& b) const {
        if (x == b.x) {
            return y < b.y;
        }
        return x < b.x;
    }

    bool operator>(const P& b) const {
        if (x == b.x) {
            return y > b.y;
        }
        return x > b.x;
    }

    int area(const P& b, const P& c) const {
        return (b - *this) * (c - *this);
    }

    ld length() {
        return sqrt(x * x + y * y);
    }
};

int sign(int x) {
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}

bool intersection(P p1, P p2, P p3, P p4) {
    // parallel lines case
    if ((p2 - p1) * (p4 - p3) == 0) {
        if ((p2 - p1) * (p3 - p1) != 0) {
            return false;
        }
        for (int i = 0; i < 2; i++) {
            if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
    }
    else {
        // non parallel lines case
        for (int i = 0; i < 2; i++) {
            if (sign((p2 - p1) * (p3 - p1)) == sign((p2 - p1) * (p4 - p1))) {
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
    }
    return true;
}

// check if c \in [a; b]
bool is_on_segment(P a, P b, P c) {
    return (c - a) * (b - a) == 0 
        && min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) 
        && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y); 
}


void solve() {

} 

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(15);
    #ifdef ONPC
        cout << "\n";
    #endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        #ifdef ONPC
           cout << "________________________\n";
        #endif
    }
     
    return 0;
}



