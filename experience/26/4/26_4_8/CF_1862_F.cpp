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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    ll n,w,f;
    cin >> w >> f >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int sum = accumulate(a.begin(),a.end(),0);
    vll dp(sum + 1);
    dp[0] = 1;
    for (int i = 0;i < n;i++)
    {
        for (int j = sum;j >= a[i];j--)
        {
            dp[j] |= dp[j - a[i]];
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0;i <= sum;i++)
    {
        if (dp[i]) 
        {
            ans = min(ans,max((i + w - 1) / w,(sum - i + f - 1) / f));
        }
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