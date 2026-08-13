#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    ll n,x,y;
    cin >> n >> x >> y;
    string a,b;
    cin >> a >> b;
    vt p;
    for (int i = 0;i < n;i++) 
    {
        if (a[i] != b[i]) p.push_back(i);
    }
    if (p.size() % 2)
    {
        cout << -1 << endl;
        return ;
    }
    if (p.empty()) 
    {
        cout << 0 << endl;
        return ;
    }
    ll ans = 0;
    if (x >= y)
    {
        if (p.size() == 2 && p[0] == p[1] - 1) ans = min(2 * y,x);
        else ans = 1LL * p.size() / 2 * y;
    }
    else 
    {
        int m = p.size();
        vll dp(m + 1);
        dp[1] = y;
        for (int i = 2;i <= m;i++)
        {
            int j1 = p[i - 2],j2 = p[i - 1];
            dp[i] = min(dp[i - 1] + y,dp[i - 2] + 2 * (j2 - j1) * x);
        }   
        ans = dp[m] / 2;
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