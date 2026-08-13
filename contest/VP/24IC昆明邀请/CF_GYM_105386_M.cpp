#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vpll a(n);
    ll xc,yc,r;
    cin >> xc >> yc >> r;
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    auto dis = [&](pll& x,pll& y)
    {
        auto [x1,y1] = x;
        auto [x2,y2] = y;
        long double A = y2 - y1,B = x1 - x2,C = x1 * y1 - x2 * y2 + y1 * x2 - x1 * y1;
        return fabs(A * xc + B * yc + C) / sqrt(A * A + B * B);
    };
    for (int i = 0;i < n;i++) 
    {
        int l = i + 1,r = n;
        auto check = [&](int j)
        {
            auto d = dis(a[i],a[j]);
            if (d < r) 
            else  

        };
        while (l + 1 < r) 
        {
            int m = l + r >> 1;
            if (check(m)) 
            else 
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}