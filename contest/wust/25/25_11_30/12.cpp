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
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> cnt(n + 1);
    int ans = 0,x = 1;
    for (int i = 1;i <= n;i++)
    {
        for (int j : g[i])
        {
            cnt[j] += g[i].size() - 1;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (cnt[i] > ans)
        {
            ans = cnt[i];
            x = i;
        }
    }
    cout << x << " " << cnt[x] << endl;
    
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