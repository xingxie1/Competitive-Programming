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
    int n;
    cin >> n;
    vvt g(n + 1,vt());
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto&& self,int u,int fa) -> bool
    {
        if (u != 1 && g[u].size() == 1) return 1;
        int cnt = 0;
        for (int v : g[u])
        {
            if (v != fa) 
            {
                if (self(self,v,u)) cnt++;
            }
        }
        if (u == 1) return cnt >= 1;
        return cnt >= 2;
    };
    if (dfs(dfs,1,0)) cout << "red" << endl;
    else cout << "purple" << endl;
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