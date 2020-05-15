#include<bits/stdc++.h>
using namespace std;

#define ll long long 
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

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> p(n);
        vector<ll> q(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            q[i] = p[i];
        }
        sort(q.begin(), q.end());
        map<ll, ll> m1;
        for (int l = 0; l < n; ++l) {
            m1[q[l]] = l;
        }
        map<ll, ll> m2;
        for (int l = 0; l < n; ++l) {
            m2[p[l]] = l;
        }
        ll x = 0;
        ll hey = 0;
        vector<vector<ll>> v(k);
            for (int j = 0; j < n; ++j) {
                if (x == k)
                    break;
                if (p[j] == q[j]) {
                    continue;}
                else {
                    if (m2[q[j]] == m1[p[j]]) {
                        continue;
                    } 
                    else {
                        v[x].pb(m2[q[j]]);
                        v[x].pb(j);
                        v[x].pb(m1[p[j]]);
                        x++;
                        ll wxw=p[m1[p[j]]];
                        ll zsz=m2[q[j]];
                        p[m2[q[j]]] = p[m1[p[j]]];
                        p[m1[p[j]]] = q[m1[p[j]]];
                        ll www=p[j];
                        p[j] = q[j];
                        m2[p[j]]=j;
                        m2[www]=m1[www];
                        m2[wxw]=zsz;
                    }
                }
            }
        vector<bool> used(n, false);
        vector<pair<ll, ll>> vv;
        for (int i = 0; i < n; ++i) {
            if (used[i] == false) {
                if (m2[q[i]] == m1[p[i]] &&p[i]!=q[i]) {
                    used[i] = true;
                    used[m1[p[i]]] = true;
                    vv.pb({i, m1[p[i]]});
                    hey++;
                } else {
                    used[i] = true;
                }
            }
        }
        if(hey%2==0) {
            for (int i = 0; i < hey; i += 2) {
                v[x].pb(vv[i].se);
                v[x].pb(vv[i].fi);
                v[x].pb(vv[i + 1].fi);
                x++;
                if (x >= k)
                    break;
                v[x].pb(vv[i + 1].se);
                v[x].pb(vv[i + 1].fi);
                v[x].pb(vv[i].se);
                x++;
                p[vv[i].fi] = q[vv[i].fi];
                p[vv[i].se] = q[vv[i].se];
                p[vv[i + 1].fi] = q[vv[i + 1].fi];
                p[vv[i + 1].se] = q[vv[i + 1].se];
                if (x >= k)
                    break;
            }
        }
            ll z = 0;
            for (int i = 0; i < n; ++i) {
                if (p[i] != q[i]) {
                    z = -1;
                }
            }
            if (z == -1) {
                cout << "-1" << "\n";
            } else {
                cout << x << "\n";
                for (int i = 0; i < x; ++i) {
                    for (auto u:v[i]) {
                        cout << u + 1 << " ";
                    }
                    cout << "\n";
                }
            }
    }
    return 0;
}
