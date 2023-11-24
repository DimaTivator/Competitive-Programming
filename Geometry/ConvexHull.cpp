// https://cses.fi/problemset/task/2195/ 

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


void solve() {
    int n;
    cin >> n;
    vector <P> p(n);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }

    sort(all(p));

    vector <P> hull;

    for (int i = 0; i < 2; i++) {
        int S = sz(hull);
        for (P c : p) {
            while (sz(hull) >= S + 2) {
                P a = hull.end()[-2];
                P b = hull.end()[-1];
                // if B is on the left from AC 
                if ((c - b) * (a - b) >= 0) {
                    break;
                }
                hull.pop_back();
            }
            hull.push_back(c);
        }
        // remove rightmost point 
        hull.pop_back();
        reverse(all(p));
    }
}

