#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n),c(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> c[i];
    vector<ll> dp(n + 1);
    for (int i = 0;i < n;i++)
    {
        dp[i] = c[i];
        for (int j = 0;j < i;j++)
        {
            if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + c[i]);
        }
    }
    ll sum = 0,mx = 0;
    for (int i = 0;i < n;i++)
    {
        mx = max(mx, dp[i]);
        sum += c[i];
    }
    cout << sum - mx << endl;
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