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
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, p, x, flag = 0, cnt = 0, total;
        cin >> n >> p;
        int a[n + 1][n + 1], b[n + 1][n + 1], c[n + 1][n + 1], d[n + 1][n + 1], ans[n + 1][n + 1];
        cout << "1 1 1 " << n << " " << n << endl;
        cin >> total;
        if(total == -1) break;
        for(int i = 1; i <= n / 2 + 1; i++){
            for(int j = n / 2; j <= n; j++){
                cout << "1 " << i << " 1 " << n << " " << j << endl;
                cin >> a[i][j];
                if(a[i][j] == -1){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
        }
        if(flag == 1) break;
        for(int i = 1; i <= n / 2; i++){
            for(int j = n / 2 + 1; j <= n; j++){
                ans[i][j] = a[i][j] + a[i + 1][j - 1] - a[i][j - 1] - a[i + 1][j];
                if(ans[i][j] == 1) cnt++;
            }
        }     
        if(cnt < total){
            for(int i = 1; i <= n / 2 + 1; i++){
                for(int j = 1;j <= n / 2 + 1; j++){
                    cout << "1 " << i << " " << j << " " << n << " " << n << endl;
                    cin >> b[i][j];
                    if(b[i][j] == -1){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            if(flag == 1) break;
            for(int i = 1; i <= n / 2; i++){
                for(int j = 1; j <= n / 2; j++){
                    ans[i][j] = b[i][j] + b[i + 1][j + 1] - b[i][j + 1] - b[i + 1][j];
                    if(ans[i][j] == 1) cnt++;
                }
            }
        }
        if(cnt < total){
            for(int i = n / 2; i <= n; i++){
                for(int j = 1;j <= n / 2 +1; j++){
                    cout << "1 1 " << j << " " << i << " " << n << endl;
                    cin >> c[i][j];
                    if(c[i][j] == -1){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            if(flag == 1) break;
            for(int i = n / 2 + 1; i <= n; i++){
                for(int j = 1; j <= n / 2; j++){
                    ans[i][j] = c[i][j] + c[i - 1][j + 1] - c[i][j + 1] - c[i - 1][j];
                    if(ans[i][j] == 1) cnt++;
                }
            }
        }
        if(cnt < total){
            for(int i = n / 2; i <= n; i++){
                for(int j = n / 2; j <= n; j++){
                    cout << "1 1 1 " << i << " " << j << endl;
                    cin >> d[i][j];
                    if(d[i][j] == -1){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            if(flag == 1) break;
            for(int i = n / 2 + 1; i <= n; i++){
                for(int j = n / 2 + 1; j <= n; j++){
                    ans[i][j] = d[i][j] + d[i - 1][j - 1] - d[i][j - 1] - d[i - 1][j];
                    if(ans[i][j] == 1) cnt++;
                }
            }
        }
        cout << " 2 " << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) 
                cout << ans[i][j] << " " ;
            cout<<endl;
        }
        cin >> x;
        if(x == -1) break;
    }
    return 0;
}