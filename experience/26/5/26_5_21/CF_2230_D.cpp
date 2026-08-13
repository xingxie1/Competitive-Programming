#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
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
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    vt pa(n + 2,n),pb(n + 2,n),dp(n + 1,n);
    ll ans = 0;
    for (int i = n - 1;i >= 0;i--) 
    {
        pa[a[i]] = i;
        pb[b[i]] = i;
        if (a[i] == b[i]) 
        {
            int x = a[i] + 1;
            if (pa[x] == pb[x]) dp[i] = dp[pa[x]];
            else dp[i] = min(pa[x],pb[x]);
        }
        if (pa[1] != pb[1]) 
        {
            ans += min(pa[1],pb[1]) - i;
        }
        else ans += dp[pa[1]] - i;
    }
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