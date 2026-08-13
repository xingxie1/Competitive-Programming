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
    ll n,p,q,r;
    cin >> n >> p >> q >> r;
    vt a(n);
    vll pre(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    for (ll x : pre) 
    {
        auto it = ranges::lower_bound(pre,x + p);
        if (it == pre.end() || *it != x + p) continue;
        it = ranges::lower_bound(pre,x + p + q);
        if (it == pre.end() || *it != x + p + q) continue;
        it = ranges::lower_bound(pre,x + p + q + r);
        if (it == pre.end() || *it != x + p + q + r) continue;
        YES;
        return ;
    }
    NO;
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