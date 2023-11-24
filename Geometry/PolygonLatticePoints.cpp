// https://cses.fi/problemset/task/2193
// Here I'm using Pick's theorem to calculate the number of lattice points 

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
 
int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}
 
void solve() {
    int n;
    cin >> n;
    vector <P> a(n);
    for (int i = 0; i < n; i++) {
        a[i].read();
    }
    a.push_back(a[0]);
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] * a[i + 1];
    }
    int lattice_boundary = 0;
    for (int i = 0; i < n; i++) {
        lattice_boundary += abs(gcd(a[i + 1].x - a[i].x, a[i + 1].y - a[i].y)) + 1;
    }
    lattice_boundary -= n;
    cout << (abs(s) - lattice_boundary) / 2 + 1 << ' ' << lattice_boundary << endl;
} 
 
