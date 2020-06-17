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
int n, m, weight;
const int N = 1e7 + 9;
int par[N];
int cnt[N];
int s[N];
int edge[N];
vector< pair<int, int> > sol;
int parent(int x){
    if(par[x] == x) return x;
    return par[x] = parent(par[x]);
}
void connect(int x, int y , vector<stack<pair<int,int>>> & A){
    int p1 = parent(x);
    int p2 = parent(y);
    if(p1 == p2){
        cnt[p1]++;
        A[p1].push({ x, y});
        return;
    }
    if(s[p2] + cnt[p2] >= s[p1] + cnt[p1]){
        swap(x, y);
        swap(p1, p2);
    }
    if(s[p1] == s[p2] && s[p1] == 1)    edge[x] = y;
    else{
        sol.push_back( {x, y} );
        if(edge[p2] != 0){
            sol.push_back({p2, edge[p2]});
            edge[p2] = 0;
        }
    }
    if(s[p1] + cnt[p1] >= s[p2] + cnt[p2]){
        par[p2] = p1;
        s[p1] += s[p2];
        cnt[p1] += cnt[p2];
    }
    else{
        par[p1] = p2;
        s[p2] += s[p1];
        cnt[p2] += cnt[p1];
    }
}
void init(){
    for(int i = 0; i <= n + 1; i++){
        edge[i] = cnt[i] = 0;
        s[i] = 1;
        par[i] = i;
    }
    sol.clear();
    weight = 0;
}
void solve(){
    int x, y, z, k, start, fro, g, f, x1, y1, ok;
    cin >> n >> m;
    init();
    vector<stack<pair<int,int>>> A(n + 1);
    for(int i = 1; i <= m; i++){
        cin >> x >> y;;
        connect(x, y, A);
    }
    for(int i = 1; i <= n; i++){
        if(parent(i) != i){
            int k = A[i].size();
            for(int j = 0; j < k; j++){
                A[par[i]].push(A[i].top());
                A[i].pop();
            }
        }
    }
    vector<pair<int,int>> vec;
    for(int i = 1; i <= n; i++){
        if(par[i] == i)   vec.push_back({cnt[i], i});
    }
    sort(vec.rbegin(), vec.rend());
    x = f = vec[0].second;
    if(edge[x] != 0)
        sol.push_back({x, edge[x]});
    z = vec.size();
    start = fro = weight = 0;
    queue<int> q;
    if(A[f].size()) q.push(f);
    for(int i = 1; i < z; i++){
        g = vec[i].second;
        if(q.empty()){
            if(start != 0){
                sol.push_back({start, g});
                start = 0;
            }
            else{
                weight += 2;
                sol.push_back({f, g});
            }
            if(edge[g] != 0)
                sol.push_back({g, edge[g]});
        }
        else{
            ok = q.front();
            if(cnt[g] == 0){
                if(edge[g] != 0){
                    x = (A[ok].top()).first;
                    y = (A[ok].top()).second;
                    A[ok].pop();
                    sol.push_back({x, g});
                    sol.push_back({y, edge[g]});
                }
                else if(start != 0){
                    sol.push_back({ start, g});
                    start = 0;
                }
                else{
                    weight += 2;
                    x = (A[ok].top()).first;
                    y = (A[ok].top()).second;
                    A[ok].pop();
                    sol.push_back({ x, g });
                    start = y;
                    fro = x;
                }
            }
            else{
                x = (A[ok].top()).first;
                y = (A[ok].top()).second;
                A[ok].pop();
                x1 = (A[g].top()).first;
                y1 = (A[g].top()).second;
                A[g].pop();
                sol.push_back({x, x1});
                A[ok].push({ y, y1});
                sol.push_back({g, edge[g]});
                if(A[g].size()) q.push( g );
            }
            if(A[ok].empty())   q.pop();
                        
        }
    }
    if(start != 0)
        sol.push_back({start, fro});
    x = 0;
    vector<int> temp;
    while(!q.empty()){
        ok = q.front();
        x += (int)(A[ok].size());
        temp.push_back(ok);
        q.pop();
    }
    x += (int)sol.size();
    cout << weight <<" "<< x << "\n";
    k = sol.size();
    for(int i = 0; i < k; i++){
        cout << sol[i].first <<" "<<sol[i].second << "\n";
    }
    k = temp.size();
    for(int i = 0 ; i < k ; i++ ){
        ok = temp[i];
        while(!A[ok].empty()){
            cout << (A[ok].top()).first <<" "<< (A[ok].top()).second << "\n";
            A[ok].pop();
        }
    }
}
signed main(){ 
	ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
}