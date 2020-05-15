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

ll convert(ll *bits) {
    ll res = 0;
    for (int i = 0; i < 63; ++i)
        res = res * 2 + bits[i];
    return res;
}

ll calculateAnd(ll *bitX, ll *bitY, ll *bitZ) {
    ll * XandZ = new ll[63];
    ll * YandZ = new ll[63];

    for (int i = 0; i < 63; ++i) {
        XandZ[i] = bitX[i] & bitZ[i];
        YandZ[i] = bitY[i] & bitZ[i];
    }
    return convert(XandZ) * convert(YandZ);
}
void solve(){
        ll X, Y, L, R;
        cin >> X >> Y >> L >> R;

        if (!X || !Y || (L == R)) {
            cout << L << "\n";
            return;
        }

        ll *LBit = new ll[63];
        ll *RBit = new ll[63];
        ll *XBit = new ll[63];
        ll *YBit = new ll[63];
        ll *ZBit = new ll[63];
        int i = 62;
        while (L > 0) {
            LBit[i--] = (L % 2);
            L /= 2;
        }
        i = 62;
        while (R > 0) {
            RBit[i--] = (R % 2);
            R /= 2;
        }
        i = 62;
        while (X > 0) {
            XBit[i--] = (X % 2);
            X /= 2;
        }
        i = 62;
        while (Y > 0) {
            YBit[i--] = (Y % 2);
            Y /= 2;
        }
        ll max, val, res;
        i = 0;
        while (i < 63 and LBit[i] == RBit[i]) {
            ZBit[i] = LBit[i];
            i++;
        }
        ZBit[i] = 0;
        bool flag = false;
        for (int j = i + 1; j < 63; ++j) {
            if (flag) {
                ZBit[j] = XBit[j] | YBit[j];
            } else {
                ZBit[j] = XBit[j] | YBit[j] | LBit[j];
                ZBit[j] > LBit[j] ? flag = true : flag;
            }
        }
        max = calculateAnd(XBit, YBit, ZBit);
        if (max == 0)
            res = convert(LBit);
        else
            res = convert(ZBit);

        ZBit[i] = 1;
        for (int j = i + 1; j < 63; ++j) {
            if (RBit[j] == 1) {
                ZBit[j] = 0;
                for (int k = j + 1; k < 63; ++k)
                    ZBit[k] = XBit[k] | YBit[k];

                val = calculateAnd(XBit, YBit, ZBit);
                if (val > max) {
                    max = val;
                    res = convert(ZBit);
                }
                ZBit[j] = 1;
            } else {
                ZBit[j] = 0;
            }
        }

        val = calculateAnd(XBit, YBit, ZBit);
        val > max ? res = convert(ZBit) : res;
        cout << res << "\n";
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) 
        solve();
    
}