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
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++ ) cin >> a[i];
    vvt g(n,vt());
    for (int i = 0;i < n - 1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vt ans(n),vis(n);
    map<int,int> cnt;
    set<int> p;
    auto dfs = [&](this auto&& self,int i) ->void
    {
        if (cnt.count(a[i]) || p.size()) ans[i] = 1;
        vis[i] = 1;
        cnt[a[i]]++;
        if (cnt[a[i]] >= 2) p.insert(a[i]);
        for (int j : g[i]) 
        {
            if (!vis[j]) self(j);
        }
        cnt[a[i]]--;
        if (cnt[a[i]] < 2) p.erase(a[i]);
        if (cnt[a[i]] == 0) cnt.erase(a[i]);
        return ;
    };
    dfs(0);
    for (int x : ans)
    {
        if (x) cout << "Yes" << endl;
        else cout << "No" << endl;
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