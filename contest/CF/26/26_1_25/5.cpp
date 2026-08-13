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
    vt a(n + 1,0);
    vt dp(n + 1,INT_MAX / 2);
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1;i <= n;i++)
    {
        if (a[i]) dp[i] = 1;
    }
    for (int i = 1;i <= n;i++)
    {
        if (!a[i]) continue;
        for (int k = i;k <= n;k += i)
        {
            dp[k] = min(dp[k],dp[k / i] + 1);
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (dp[i] == INT_MAX / 2) cout << -1 << " ";
        else cout << dp[i] << " ";
    }
    cout << endl;
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