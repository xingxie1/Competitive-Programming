#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    int sum = (n + 1) * n / 2;
    if (sum & 1)
    {
        cout << 0 << endl;
        return ;
    }
    sum /= 2;
    vll dp(sum + 1);
    dp[0] = 1;
    for (int i = 1;i <= n;i++)
    {
        for (int j = sum;j >= i;j--)
        {
            dp[j] += dp[j - i];
        }
    }
    cout << dp[sum] / 2 << endl;
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