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
    int n,k;
    cin >> n >> k;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    int l = -1,r = INT_MAX / 2;
    auto check = [&](int x)
    {
        ll cnt = 0;
        for (int i = 0;i < n;i++) 
        {
            cnt += max(0,(a[i] - x + b[i] - 1) / b[i]);
        }
        return cnt >= k;
    };
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    ll ans = 0,all = 0;
    ll cc = 0;
    for (int i = 0;i < n;i++)
    {
        ll cnt = max(0,(a[i] - l + b[i] - 1) / b[i]);
        cc += cnt;
        all += (a[i] + b[i] - 1) / b[i];
        ans += 1LL * cnt * a[i] - 1LL * cnt * (cnt - 1) * b[i] / 2;
    }
    k = min(1LL * k,all);
    ans += r * (k - cc);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}