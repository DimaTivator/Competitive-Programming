// https://cses.fi/problemset/task/2192

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
 
    bool operator<(const P& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
 
    bool operator>(const P& other) const {
        if (x == other.x) {
            return y > other.y;
        }
        return x > other.x;
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
 
bool is_on_segment(P a, P b, P c) {
    return (c - a) * (b - a) == 0 
        && min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) 
        && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y); 
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector <P> p(n);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }
    p.push_back(p[0]);
    for (int k = 0; k < m; k++) {
        P x;
        x.read();
        P y = { x.x + 1, INF };
        int cnt = 0;
        bool boundary = false;
        for (int i = 0; i < n; i++) {
            if (is_on_segment(p[i], p[i + 1], x)) {
                boundary = true;
            }
            if (intersection(x, y, p[i], p[i + 1])) {
                cnt ^= 1;
            }
        }
        if (boundary) {
            cout << "BOUNDARY" << endl;
        }
        else {
            cout << (cnt ? "INSIDE" : "OUTSIDE") << endl;
        }
    }
} 
