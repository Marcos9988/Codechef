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
int swapstep(vector<int> & a){
    int ans = 0, i = 0, n = a.size();
    while(i < n){
        if(a[i] != i + 1){
            while(a[i] != i + 1){
                swap(a[a[i] - 1], a[i]);
                ans++;
            }
        }
        i++;
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    V a(n);
    for(auto &i : a)    cin >> i;
    while(m--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(a[x] > a[y])
            swap(a[x], a[y]);
    }
    int k = swapstep(a);
    cout<<k<<endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
}