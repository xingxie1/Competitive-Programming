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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
// const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vvt isp(n + 1,vt(n + 1));
    for (int len = 1;len <= n;len++)
    {
        for (int l = 1;l + len - 1 <= n;l++)
        {
            int r = l + len - 1;
            if (s[l] == s[r])
            {
                if (r - l <= 2) isp[l][r] = 1;
                else isp[l][r] = isp[l + 1][r - 1];
            }
        }
    }
    vll dp(n + 1),ways(n + 1);
    ways[0] = 1;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 0;j < i;j++)
        {
            if (isp[j + 1][i])
            {
                ll L = i - j;
                L = L * L % mod;
                ways[i] = (ways[i] + ways[j]) % mod;
                ll v = (ways[j] * L) % mod;
                dp[i] = (dp[i] + dp[j] + v) % mod;
            }
        }
    }
    cout << dp[n] << endl;
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