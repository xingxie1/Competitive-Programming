#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
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
    // for (int i = 0;i <= 5e3;i++) 
    // {
    //     for (int j = i;j <= 5e3;j++)
    //     {
    //         int x = 8;
    //         ll ans = 0;
    //         ll l = i,r = j;
    //         for (int ii = l;ii <= r;ii++)
    //         {
    //             if (ii % x == 0) ans ^= ii;
    //         }
    //         // cout << ans << " ";
    //         r /= x;
    //         r *= x;
    //         if (l % x == 0) l -= x;
    //         else 
    //         {
    //             l /= x;
    //             l *= x;
    //         }
    //         // cout << l << " " << r << endl;
    //         auto f = [&](int y) -> ll
    //         {
    //             int c = y / x;
    //             if (c % 4 == 1) return x;
    //             if (c % 4 == 2) return y + x;
    //             if (c % 4 == 3) return 0;
    //             if (c % 4 == 0) return y; 
    //             return 0ll;
    //         };
    //         // cout << f(l) << " " << f(r) << endl;
    //         // cout << (f(r) ^ f(l)) << endl;
    //         ll ans2 = f(r) ^ f(l);
    //         if (ans != ans2) 
    //         {
    //             cout << "!!!" << ans << " " << ans2 << endl;
    //         }
    //     }
    // }
    ll l,r,x;
    cin >> l >> r >> x;
    if (r < x) 
    {
        cout << 0 << endl;
        return;
    }
    if (l < x) 
    {
        l = 0;
    }
    else 
    {
        r /= x;
        r *= x;
        if (l % x == 0) l -= x;
        else 
        {
            l /= x;
            l *= x;
        }
    }
    // cout << l << " " << r << endl;
    auto f = [&](int y) -> ll
    {
        int c = y / x;
        if (c % 4 == 1) return x;
        if (c % 4 == 2) return y + x;
        if (c % 4 == 3) return 0;
        if (c % 4 == 0) return y; 
        return 0ll;
    };
    // cout << f(l) << " " << f(r) << endl;
    cout << (f(r) ^ f(l)) << endl;
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