#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).end()
#define pb push_back
#define pf push_front
#define fori(i, a, n) for(int i = a; i < n; ++i)
#define MAX(x) (*max_element(all(x)))
#define MIN(x) (*min_element(all(x)))
#define sortarr(a,n) sort(a, a+n)
#define sortvec(V) sort(all(V))

typedef vector<int> V;
typedef pair<int , int> pairi;
typedef set<int> seti;
typedef deque<int> deqi;

void solve(){
    int p, q, r, a, b, c, f = 0;
    cin >> p >> q >> r >> a >> b >> c;
    if(p == a && q == b && r == c) cout << 0;
    else if((p == a && q == b) || (q == b && r == c) || (p == a && r == c)) cout << 1;
    else if(p == a) {
        if((!q || !r) && q - b == r - c) cout << 1;
        else if(q && r && (q - b == r - c || (b / q == c / r && b % q == 0 && c % r == 0))) cout << 1;
        else cout << 2;
    }
    else if(q == b) {
        if((!p || !r) && p - a == r - c) cout << 1;
        else if(p && r && (p - a == r - c || (a / p == c / r && a % p == 0 && c % r == 0))) cout << 1;
        else cout << 2;
    }
    else if(r == c) {
        if((!p || !q) && p - a == q - b) cout << 1;
        else if(p && q && (p - a == q - b || (b / q == a / p && b % q == 0 && a % p == 0))) cout << 1;
        else cout << 2;
    }
    else if((p - a == q - b) && (q - b == r - c) && (r - c == p - a)) cout << 1;
    else if(p && q && r && b / q == c / r && a / p == c / r && b / q == a / p && a % p == 0 && b % q == 0 && c % r == 0) cout << 1;
    else if((p - a == q - b) || (q - b == r - c) || (r - c == p - a)) cout << 2;
    else if(q && p && b / q == a / p && b % q == 0 && a % p == 0) cout << 2;
    else if(q && r && b / q == c / r && b % q == 0 && c % r == 0) cout << 2;
    else if(p && r && a / p == c / r && a % p == 0 && c % r == 0) cout << 2;
    else if(p - a == q - b + r - c || q - b == p - a + r - c || r - c == p - a + q - b) cout << 2;
    else if((p && q && r && a % p == 0 && b % q == 0 && c % r == 0) && (a / p * b / q == c / r || b / q * c / r == a / p || c / r * a / p == b / q)) cout << 2;
    else {
        if(p && a % p == 0) {
            int k = a / p;
            if(q * k - b == r - c || r * k - c == q - b) f = 1, cout << 2;
            else if(k && ((c % k == 0 && q - b == r - c / k) || (b % k == 0 && r - c == q - b / k))) f = 1, cout << 2;
        }
        if(!f && q && b % q == 0) {
            int k = b / q;
            if(p * k - a == r - c || r * k - c == p - a) f = 1, cout << 2;
            else if(k && ((a % k == 0 && r - c == p - a / k) || (c % k == 0 && p - a == r - c / k))) f = 1, cout << 2;
        }
        if(!f && r && c % r == 0) {
            int k = c / r;
            if(p * k - a == q - b || q * k - b == p - a) f = 1, cout << 2;
            else if(k && ((b % k == 0 && p - a == q - b / k) || (a % k == 0 && q - b == p - a / k))) f = 1, cout << 2;
        }
        if(!f && (p != q) && (a - b) % (p - q) == 0) {
            int k =  (a - b) / (p - q);
            if(p * k - a == r * k - c) f = 1, cout << 2;
            else if(p * k - a == r - c) f = 1, cout << 2;
            else if(r * k == c) f = 1, cout << 2;
            else if(k && a % k == 0 && b % k == 0 && c - r == a / k - p && c - r == b / k - q) f = 1, cout << 2;
        }
        if(!f && (q != r) && (b - c) % (q - r) == 0) {
            int k =  (b - c) / (q - r);
            if(q * k - b == p * k - a) f = 1, cout << 2;
            else if(q * k - b == p - a) f = 1, cout << 2;
            else if(p * k == a) f = 1, cout << 2;
            else if(k && c % k == 0 && b % k == 0 && a - p == b / k - q && a - p == c / k - r) f = 1, cout << 2;
        }
        if(!f && (r != p) && (c - a) % (r - p) == 0) {
            int k =  (c - a) / (r - p);
            if(r * k - c == q * k - b) f = 1, cout << 2;
            else if(r * k - c == q - b) f = 1, cout << 2;
            else if(q * k == b) f = 1, cout << 2;
            else if(k && a % k == 0 && c % k == 0 && b - q == a / k - p && b - q == c / k - r) f = 1, cout << 2;
        }
        if(!f) cout << 3;
    }
    cout << endl;
}
signed main() {
    int t; 
    cin >> t;
    while(t--) 
        solve(); 
}
