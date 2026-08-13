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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        a[i]--;
    }
    int cnt = 0;
    vt pre(n);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < i;j++)
        {
            if (a[j] > a[i]) 
            {
                cnt++;
                pre[a[j]] |= 1 << a[i];
            }
        }
    }
    if (cnt == 0) 
    {
        ll ans = 1;
        for (int i = 1;i <= n;i++) ans = ans * i % MOD;
        cout << ans << endl;
        return ;
    }
    vt dp(1 << n);
    dp[0] = 1;
    int all = (1 << n) - 1;
    for (int mask = 0;mask < 1 << n;mask++)
    {
        for (int i = 0;i < n;i++) 
        {
            if (mask >> a[i] & 1) continue;
            if ((pre[a[i]] & (all ^ mask)) == 0) 
            {
                dp[mask | 1 << a[i]] = (dp[mask | 1 << a[i]] + dp[mask]) % MOD;
            }
        }
    }
    cout << 2 * dp[all] % MOD << endl;
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