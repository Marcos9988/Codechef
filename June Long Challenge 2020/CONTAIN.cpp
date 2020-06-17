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

const int MOD = 1e9+7;
const int INF = 1e9+8;
const double pi = 3.14159265359;
struct Point {
    int x, y;
    bool operator == (Point a){
        return a.x == x && a.y == y;
    }
};
vector< vector < Point > > ans;
bool cmp(Point a, Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cross(Point a, Point b, Point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool cross_pro(Point a, Point b, Point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
int orient(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0; 
    return (val > 0) ? 1 : 2; 
}
void convex_hull(vector<Point> & a) {
    if (a.size() == 1)  return;
    sort(a.begin(), a.end(), & cmp);
    Point p1 = a[0], p2 = a.back();
    vector<Point> A, B;
    A.push_back(p1), B.push_back(p1);
    for (int i = 1; i < a.size(); i++) {
        if (i == a.size() - 1 || cross(p1, a[i], p2)) {
            while (A.size() >= 2 && !cross(A[A.size() - 2], A[A.size() - 1], a[i]))
                A.pop_back();
            A.push_back(a[i]);
        }
        if (i == a.size() - 1 || cross_pro(p1, a[i], p2)) {
            while(B.size() >= 2 && !cross_pro(B[B.size() - 2], B[B.size() - 1], a[i]))
                B.pop_back();
            B.push_back(a[i]);
        }
    }
    vector<Point> v;
    for (int i = 0; i < A.size(); i++){
        v.push_back(A[i]);
        a.erase(remove(a.begin(), a.end(), A[i]), a.end());
    }
    for (int i = B.size() - 2; i > 0; i--){
        v.push_back(B[i]);
        a.erase(remove(a.begin(), a.end(), B[i]), a.end());
    }
    vector<Point> temp = a;
    for(auto it : temp){
        for(int i = 0; i < v.size(); ++i){
            int x = orient(v[i], v[(i+1) % v.size()], it);
            if(!x) a.erase(remove(a.begin(), a.end(), it), a.end());
        }
    }
    ans.pb(v);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<Point> points(n);
    for(int i = 0; i < n; ++i){
        int c, d;
        cin >> c >> d;
        points[i].x = c;
        points[i].y = d;
    }
    vector<Point> temp = points;
    while(temp.size() > 2)
           convex_hull(temp);
    temp.clear();
    while(q--){
        int cnt = 0;
        Point P;
        cin >> P.x >> P.y;
        for(auto it : ans){
            bool ok = false;
            for(int i = 0; i < it.size(); ++i){
                if(!cross(it[i], it[(i + 1) % it.size()], P)) {
                    ok = true;
                    break;
                }
            }
            if(!ok) cnt++;
            else break;
        }
        cout << cnt << endl;
    }
    ans.clear();
    points.clear();
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
}