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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt vis(n,vt(m));
    vvt vis2(n,vt(m));
    vvt ans;
    for (int len = (min(n,m) - 1) / 2;len >= 1;len--)
    {
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
            {
                if (a[i][j] == '*' && !vis2[i][j])
                {
                    // cout << i << " " << j << endl;
                    if (i - len < 0 || i + len >= n) continue;
                    if (j - len < 0 || j + len >= m) continue;
                    int f = 1;
                    for (int i1 = i - len;i1 <= i + len;i1++) 
                    {
                        if (a[i1][j] != '*') f = 0;
                    }
                    if (!f) continue;
                    for (int j1 = j - len;j1 <= j + len;j1++) 
                    {
                        if (a[i][j1] != '*') f = 0;
                    }
                    if (!f) continue;
                    for (int i1 = i - len;i1 <= i + len;i1++) 
                    {
                        vis[i1][j] = 1;
                    }
                    for (int j1 = j - len;j1 <= j + len;j1++) 
                    {
                        vis[i][j1] = 1;
                    }
                    vis2[i][j] = 1;
                    ans.push_back({i + 1,j + 1,len});
                }
            }
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '*' && !vis[i][j]) 
            {
                cout << -1 << endl;
                return ;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0;i < ans.size();i++)
    {
        for (int x : ans[i]) cout << x << " ";
        cout << endl;
    }
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