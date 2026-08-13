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
    int n,k;
    cin >> n >> k;
    if (k >= 65)
    {
        cout << 0 << endl;
        return ;
    }
    int d = 0,t = n;
    while (t > 1) 
    {
        t >>= 1;
        d++;
    }
    vector<vector<int>> dp(65,vector<int>(65));
    for  (int i = 1;i <= k;i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1;i <= d;i++)
    {
        for (int j = 1;j <= k;j++)
        {
            int tt = 0;
            if (j >= 2)
            {
                tt = 1 + dp[i - 1][j - 2];
                if (i <= j - 2) tt--;
            } 
            else if (j == 1) tt = 1;
            dp[i][j] = dp[i - 1][j - 1] + tt;
        }
    }
    cout << n - dp[d][k] << endl;

    
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