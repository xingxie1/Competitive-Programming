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
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
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

ll qpow(ll a,ll b) 
{
    ll r = 1;
    while (b) 
    {
        if (b & 1) r = r * a;
        a = a * a;
        b >>= 1;
    }
    return r;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<umap<ll,ll>> cnt(11);
    auto f = [&](int x) 
    {
        int r = 0;
        while (x) 
        {
            x /= 10;
            r++;
        }
        return r;
    };
    for (int i = 0;i < n;i++) 
    {
        int x = a[i] % m;
        for (int len = 1;len <= 10;len++) 
        {
            ll r = x * qpow(10,len) % m;
            cnt[len][r]++;
        }
    }
    ll ans = 0;
    for (int i = 0;i < n;i++) 
    {
        int t = (m - a[i] % m) % m;
        int len = f(a[i]);
        ans += cnt[len][t];
    }
    cout << ans << endl;
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