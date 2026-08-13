#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = INT_MAX;
    for (int d = 0;d < 26;d++)
    {
        vector dp(n + 1,vector<int>(26,0));
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < 26;j++)
            {
                dp[i + 1][j] = min(dp[i][(j - d + 26) % 26],dp[i][(j + d + 26) % 26]) + (s[i] - 'a' != j);
            }
        }
        ans = min(ans,ranges::min(dp[n]));
    }
    cout << ans << endl;
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