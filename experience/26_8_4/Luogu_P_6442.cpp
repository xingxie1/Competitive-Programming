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
const int MOD = (int)1e9+7;

ll qpow(ll a,ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n);
    int N = 1 << m;
    vt f(N),dp(N);
    for (int i = 0;i < n;i++)
    {
        int k;
        cin >> k;
        for (int j = 0;j < k;j++) 
        {
            int x;
            cin >> x;
            x--;
            a[i] |= 1 << x;
        }
        f[a[i]]++;
    }
    for (int i = 0;i < m;i++)
    {
        for (int mask = 0;mask < N;mask++)
        {
            if (mask >> i & 1)
            {
                f[mask] += f[mask ^ (1 << i)];
            }
        }
    }
    ll ans = 0;
    for (int mask = 0;mask < N;mask++)
    {
        int b = popcount(1u * mask);
        ll x = (m - b) % 2 ? -1 : 1;
        ans = (ans + x * qpow(2,f[mask])) % MOD;
        if (ans < 0) ans += MOD;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}