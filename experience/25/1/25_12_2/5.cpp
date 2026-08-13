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
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vt p(m);
    for (int i = 0;i < m;i++) cin >> p[i];
    vector<vector<int>> pre(n + 1,vector<int>(26));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < 26;j++)
        {
            if (s[i] - 'a' != j) pre[i + 1][j] = pre[i][j];
            else pre[i + 1][j] = pre[i][j] + 1;
        }
    }
    vector<ll> ans(26);
    for (int i = 0;i < m;i++)
    {
        for (int j = 0;j < 26;j++)
        {
            ans[j] += pre[p[i]][j];
        }
    }
    for (int j = 0;j < 26;j++) ans[j] += pre[n][j];

    for (int x : ans) cout << x << " ";
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