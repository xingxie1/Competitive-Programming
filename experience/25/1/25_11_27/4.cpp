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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(10);
    dp[0] = 1;
    for (int i = 0;i < n;i++)
    {
        int x = s[i] - '0';
        for (int j = 9;j >= 0;j--)
        {
            dp[j] += dp[(j - x + 9) % 9];
            dp[j] %= MOD;
        }
    }
    
    cout << (dp[9] - 1 + MOD) % MOD;
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