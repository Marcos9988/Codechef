#include <bits/stdc++.h>
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
#define inf 998244353
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
struct Node 
{
    char data;
    ll p[5],d;
    Node *left, *right, *parent;
};
ll mod(ll a, ll m)
{
    return (a%m + m) % m;
}
ll mul_inv(ll a, ll b)
{
    ll b0 = b, t, q;
    ll x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = mod(a,b), a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}
ll mod_inv(ll a)
{
    return mul_inv(a,inf);
}

ll mod_mult(ll a, ll b)
{
    return mod(a*b,inf);
}
vector<ll> eval(Node *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data=='^')
        {
            root->p[1] = root->p[2] = root->p[3] = root->p[4] = 1;
            root->d = 4;
        }
        else if(root->data=='&')
        {
            root->p[1] = 9;root->p[2]=3;root->p[3]=3;root->p[4]=1;
            root->d=16;
        }
        else if(root->data=='|')
        {
            root->p[1] = 1;root->p[2]=3;root->p[3]=3;root->p[4]=9;
            root->d=16;
        }
        return {root->d,root->p[1],root->p[2],root->p[3],root->p[4]};
    }
    else if(root->left!=NULL && root->right!=NULL)
    {   vector<ll> left,right;
        left = eval(root->left); right = eval(root->right);
        ll mult[5][5];
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                mult[i][j]=mod_mult(left[i],right[j]);
            }
        }
        if(root->data=='^')
        {
            root->d = mod_mult(root->left->d,root->right->d);
            root->p[1] = mod(mod(mult[1][1]+mult[2][2],inf) + mod(mult[3][3]+mult[4][4],inf),inf);
            root->p[2] =
            mod(mod(mult[3][4]+mult[4][3],inf) + mod(mult[1][2]+mult[2][1],inf),inf);
            root->p[3] =
            mod(mod(mult[3][1]+mult[1][3],inf) + mod(mult[4][2]+mult[2][4],inf),inf);
            root->p[4] =
            mod(mod(mult[1][4]+mult[2][3],inf) + mod(mult[3][2]+mult[4][1],inf),inf);
        }
        else if(root->data=='&')
        {
            root->d = mod_mult(root->left->d,root->right->d);
            root->p[1] = mod(mod(mod(mod(mod(mod(mod(mod(mult[1][1]+mult[1][2],inf)+mult[1][3],inf)+mult[1][4],inf)+mult[2][1],inf)+mult[3][1],inf)+mult[4][1],inf)+mult[2][3],inf)+mult[3][2],inf);
            root->p[2] = mod(mod(mult[2][4]+mult[4][2],inf)+mult[2][2],inf);
            root->p[3] = mod(mod(mult[3][4]+mult[4][3],inf)+mult[3][3],inf);
            root->p[4] = mult[4][4];
        }
        else if(root->data=='|')
        {
            root->d = mod_mult(root->left->d,root->right->d);
            root->p[1] = mult[1][1];
            root->p[2] = mod(mod(mult[2][1]+mult[1][2],inf)+mult[2][2],inf);
            root->p[3] = mod(mod(mult[1][3]+mult[3][1],inf)+mult[3][3],inf);
            root->p[4] = mod(mod(mod(mod(mod(mod(mod(mod(mult[4][1]+mult[4][2],inf)+mult[4][3],inf)+mult[4][4],inf)+mult[3][4],inf)+mult[2][4],inf)+mult[1][4],inf)+mult[2][3],inf)+mult[3][2],inf);
        }
        return {root->d,root->p[1],root->p[2],root->p[3],root->p[4]};
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        vector<ll> right;
        right = eval(root->right);
        ll mult[5][5];
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                mult[i][j]=right[j];
            }
        }
        if(root->data=='^')
        {
            root->d = mod_mult(4,right[0]);
            root->p[1] = mod(mod(mult[1][1]+mult[2][2],inf) + mod(mult[3][3]+mult[4][4],inf),inf);
            root->p[2] =
            mod(mod(mult[3][4]+mult[4][3],inf) + mod(mult[1][2]+mult[2][1],inf),inf);
            root->p[3] =
            mod(mod(mult[3][1]+mult[1][3],inf) + mod(mult[4][2]+mult[2][4],inf),inf);
            root->p[4] =
            mod(mod(mult[1][4]+mult[2][3],inf) + mod(mult[3][2]+mult[4][1],inf),inf);
        }
        else if(root->data=='&')
        {
            root->d = mod_mult(4,right[0]);
            root->p[1] = mod(mod(mod(mod(mod(mod(mod(mod(mult[1][1]+mult[1][2],inf)+mult[1][3],inf)+mult[1][4],inf)+mult[2][1],inf)+mult[3][1],inf)+mult[4][1],inf)+mult[2][3],inf)+mult[3][2],inf);
            root->p[2] = mod(mod(mult[2][4]+mult[4][2],inf)+mult[2][2],inf);
            root->p[3] = mod(mod(mult[3][4]+mult[4][3],inf)+mult[3][3],inf);
            root->p[4] = mult[4][4];
        }
        else if(root->data=='|')
        {
            root->d = mod_mult(4,right[0]);
            root->p[1] = mult[1][1];
            root->p[2] = mod(mod(mult[2][1]+mult[1][2],inf)+mult[2][2],inf);
            root->p[3] = mod(mod(mult[1][3]+mult[3][1],inf)+mult[3][3],inf);
            root->p[4] = mod(mod(mod(mod(mod(mod(mod(mod(mult[4][1]+mult[4][2],inf)+mult[4][3],inf)+mult[4][4],inf)+mult[3][4],inf)+mult[2][4],inf)+mult[1][4],inf)+mult[2][3],inf)+mult[3][2],inf);
        }
        return {root->d,root->p[1],root->p[2],root->p[3],root->p[4]};
    }
    else if(root->left!=NULL && root->right==NULL)
    {
        vector<ll> left;
        left = eval(root->left);
        ll mult[5][5];
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                mult[i][j]=left[i];
            }
        }
        if(root->data=='^')
        {
            root->d = mod_mult(4,left[0]);
            root->p[1] = mod(mod(mult[1][1]+mult[2][2],inf) + mod(mult[3][3]+mult[4][4],inf),inf);
            root->p[2] =
            mod(mod(mult[3][4]+mult[4][3],inf) + mod(mult[1][2]+mult[2][1],inf),inf);
            root->p[3] =
            mod(mod(mult[3][1]+mult[1][3],inf) + mod(mult[4][2]+mult[2][4],inf),inf);
            root->p[4] =
            mod(mod(mult[1][4]+mult[2][3],inf) + mod(mult[3][2]+mult[4][1],inf),inf);
        }
        else if(root->data=='&')
        {
            root->d = mod_mult(4,left[0]);
            root->p[1] = mod(mod(mod(mod(mod(mod(mod(mod(mult[1][1]+mult[1][2],inf)+mult[1][3],inf)+mult[1][4],inf)+mult[2][1],inf)+mult[3][1],inf)+mult[4][1],inf)+mult[2][3],inf)+mult[3][2],inf);
            root->p[2] = mod(mod(mult[2][4]+mult[4][2],inf)+mult[2][2],inf);
            root->p[3] = mod(mod(mult[3][4]+mult[4][3],inf)+mult[3][3],inf);
            root->p[4] = mult[4][4];
        }
        else if(root->data=='|')
        {
            root->d = mod_mult(4,left[0]);
            root->p[1] = mult[1][1];
            root->p[2] = mod(mod(mult[2][1]+mult[1][2],inf)+mult[2][2],inf);
            root->p[3] = mod(mod(mult[1][3]+mult[3][1],inf)+mult[3][3],inf);
            root->p[4] = mod(mod(mod(mod(mod(mod(mod(mod(mult[4][1]+mult[4][2],inf)+mult[4][3],inf)+mult[4][4],inf)+mult[3][4],inf)+mult[2][4],inf)+mult[1][4],inf)+mult[2][3],inf)+mult[3][2],inf);
        }
        return {root->d,root->p[1],root->p[2],root->p[3],root->p[4]};
    }
}


int main()
{
    int t;
    cin>>t;
    std::cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);//((#&#)&#)
        if(s=="#") cout<<"748683265 748683265 748683265 748683265\n";
        else
        {
            Node* head = new Node();
            head->left = NULL;
            head->right = NULL;
            head->parent = NULL;
            
            for(ll i=1;i<s.size()-1;i++)
            {
                if(s[i]=='(')
                {
                    Node* new_node = new Node();
                    new_node->left = NULL;
                    new_node->right = NULL;
                    if(s[i-1]=='(')
                    {head->left = new_node;
                        head->left->parent = head;
                        head = head->left;}
                    else
                    {head->right = new_node;
                    head->right->parent = head;
                        head = head->right;}
                }
                else if(s[i]=='^') head->data = '^';
                else if(s[i]=='&') head->data = '&';
                else if(s[i]=='|') head->data = '|';
                else if(s[i]==')') head = head->parent;
                
            }
            vector<ll> result;
            result=eval(head);
            ll m12;
            m12 = mod_inv(result[0]);
            
            cout<<mod_mult(result[1],m12)<<" "<<mod_mult(result[4],m12)<<" "<<mod_mult(result[2],m12)<<" "<<mod_mult(result[3],m12)<<"\n";
            
        }
        
    }
}

