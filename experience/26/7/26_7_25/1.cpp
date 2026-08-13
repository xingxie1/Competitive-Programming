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
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
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
    ll n,m;
    cin >> n >> m;
    vpll a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    ll l = -1,r = LLONG_MAX / 2;
    auto check = [&](ll x) 
    {
        ll cnt = 0;
        for (auto& [h,c] : a) 
        {
            cnt += max(0LL,h - max(x,c));
        }
        return cnt < m;
    };
    while (l + 1 < r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }   
    // cout << r << endl;
    ll ans = 0,cnt = 0,all = 0;
    for (auto& [h,c] : a)
    {
        ll nn = max(0LL,h - max(c,r));
        ans += nn * (2 * h - nn);
        cnt += nn;
        all += h - c;
    }
    m = min(m,all);
    ans += 1LL * (2 * r - 1) * (m - cnt); 
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