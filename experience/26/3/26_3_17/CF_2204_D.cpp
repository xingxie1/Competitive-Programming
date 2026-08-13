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
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vvt g(n + 1,vt());
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    vector<int> color(n + 1,-1);
    for (int i = 1;i <= n;i++)
    {
        if (color[i] != -1) continue;
        color[i] = 0;
        vector<int> cnt = {0,0};
        queue<int> q;
        q.push(i);
        int flag = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cnt[color[u]]++;
            for (int v : g[u])
            {
                if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[u] == color[v]) flag = 0;
            }
        }
        if (flag) ans += max(cnt[0],cnt[1]);
    }
    cout << ans << endl;
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