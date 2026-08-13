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
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<char>> g(n,vector<char>(m));
    vector<vector<int>> s(n + 1,vector<int>(m + 1));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) 
        {
            cin >> g[i][j];
            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + g[i][j] - '0'; 
        }
    }
    int ans = INT_MAX;
    for (int i = 0;i <= n;i++)
    {
        for (int j = 0;j <= m;j++)
        {
            for (int i1 = i;i1 <= n;i1++)
            {
                for (int j1 = j;j1 <= m;j1++)
                {
                    if (s[i1][j1] - s[i][j1] - s[i1][j] + s[i][j] >= k)
                    {
                        ans = min(ans,(i1 - i) * (j1 - j));
                    }
                }
            }
            // cout << s[i][j] << " ";
        }
        // cout << endl;
    }
    if (ans == INT_MAX) cout << 0 << endl;
    else cout << ans << endl;
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