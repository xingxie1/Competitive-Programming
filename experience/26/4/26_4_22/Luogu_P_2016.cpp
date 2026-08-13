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
    int n;
    cin >> n;
    vvt g(n);
    for (int i = 0;i < n;i++)
    {
        int id,k;
        cin >> id >> k;
        for (int j = 0;j < k;j++)
        {
            int x;
            cin >> x;
            g[id].push_back(x);
            g[x].push_back(id);
        }
    }
    auto dfs = [&](auto&& self,int u,int fa) -> pii
    {
        pii ans = {1,0};
        for (int v : g[u])
        {
            if (v == fa) continue;
            auto [l,nl] = self(self,v,u);
            ans.fi += min(l,nl);
            ans.se += l;
        }   
        // cout << ans.fi << " " << ans.se << endl;
        return ans;
    };
    pii ans = dfs(dfs,0,-1);
    cout << min(ans.fi,ans.se) << endl;
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