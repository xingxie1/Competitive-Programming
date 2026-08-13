#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    // vector g(m + 1,vvpii(n + 1));
    map<int,vvpii> g;
    for (int i = 0;i < m;i++) 
    {
        int u,v,c,l;
        cin >> u >> v >> c >> l;
        u--;v--;c--;
        auto& f = g[c];
        f.resize(n);
        f[v].push_back({u,l});
        f[u].push_back({v,l});
    }
    vt vis(n);
    set<int> st;
    st.insert(0);
    vis[0] = 1;
    for (int i = 0;i < k;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        set<int> nst = st;
        for (int x : st)
        {
            auto dfs = [&](auto&& self,int u,int res) -> void
            {
                auto& f = g[a];
                for (auto& [v,l] : f[u]) 
                {
                    // cout << "u v l " << u << " " << v << " " << l << endl;
                    if (!vis[v] && l <= res) 
                    {
                        vis[v] = 1;
                        nst.insert(v);
                        self(self,v,res - l);
                        // cout << "v : " << v << endl;
                    }
                }
            };
            dfs(dfs,x,b);
            // cout << "x : " << x << endl;
        }
        st = nst;
    }
    for (int i = 0;i < n;i++) 
    {
        if (vis[i]) cout << 1;
        else cout << 0;
    }
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