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

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int fac(int x)
{
    if(x == 0)  return 1;
    return (x * fac(x - 1)); 
}
template <class T> 
T gcd(T x, T y)     // template function to find gcd of two numbers
{
    T gc;
    for(T i = 1; i <= x && i <= y; i++)
    {
        if(x%i == 0 && y % i == 0)
            gc = i;
    }
    return gc;
}
template <class T>
T fac(T n)      // template function to find factorial of a number
{ 
    T res = 1, i; 
    for (i = 2; i <= n; i++) 
        res *= i; 
    return res; 
}

template<class T>
T lcm(T a, T b)     //template function to find lcm of two numbers 
{
    return (a * b)/gcd(a,b);
}

string tostring(int a)      //converting integer into a string
{
    string ans;
    while(a){
        ans += char(a % 10 + '0');
        a /= 10;
    }
    return ans;
}
void solve()
{
    int n,m,k; 
    cin>>n>>m>>k;
    int a[501][5001], l = 0, b[10] = {0};
    int ma = 0, mi = INT_MAX, max, min, s[500] = {0};
    fori(i, 0, n)
    {
        for(int j = 1; j <= m; j++)  b[j] = 0;
        for(int j = 0; j < k; j++)
        {
            cin>>a[i][j]; 
            b[a[i][j]]++;
        }
        max = 0, min = 0, ma = 0, mi = INT_MAX;
        for(int j = 1; j <= m; j++)
        {
            if(b[j] > ma)
            {
                ma = b[j];
                max = j;
            }
            if(b[j] < mi && b[j] != 0)
            {
                mi = b[j];
                min = j;
            }
        }
        cout<<max<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    solve();
}