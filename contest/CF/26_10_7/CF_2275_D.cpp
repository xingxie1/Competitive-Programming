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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    ll n,k;
    cin >> n >> k;
    vll a(n),b(n),c(n);
    for (int i = 0;i < n;i++) cin >> a[i] >> b[i] >> c[i];
    ll l = -2e18,r = 2e18;
    auto check = [&](ll t) 
    {
        ll cnt = 0;
        for (int i = 0;i < n;i++)
        {
            ll s = a[i] + b[i] + c[i];
            if (s >= t) continue;
            if (a[i] > b[i] || a[i] > c[i] || b[i] > c[i]) cnt += t - s;
            else 
            {
                ll d1 = b[i] - a[i],d2 = c[i] - b[i];
                if (d1 == 0 && d2 == 0) return false;
                ll mn = min(d1,d2);
                cnt += mn + 1;
                s -= mn + 1;
                cnt += t - s;
            }
            if (cnt > k) return false;
        }
        return cnt <= k;
    };
    while (l + 1 < r) 
    {
        ll m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    ll ans = l;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}