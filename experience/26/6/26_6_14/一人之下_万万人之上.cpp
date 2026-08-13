#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using ll = long long;
using pii = pair<int,int>;

class unionfind 
{
    vt fa,sz;
    ll ans = 0;
public:
    int cc;
    unionfind (int n) : fa(n), sz(n, 1),cc(n) 
    {
        iota(fa.begin(),fa.end(),0);
    }
    int find(int x) 
    {
        if (fa[x] != x) 
        {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    bool is_same(int x,int y) 
    {
        return find(x) == find(y);
    }
    bool merge(int from,int to)
    {
        int x = find(from),y = find(to);
        if (x == y) return false;
        fa[x] = y;
        ans += 1LL * sz[y] * sz[x];
        sz[y] += sz[x];
        // cout << "@@" << sz[y] << endl;
        cc--;
        return true;
    }
    int get_size(int x) {return sz[x];}
    ll get_ans()
    {
        return ans;
    }
};
void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    vector<vt> edge(m);
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        edge[i] = {u,v,w};
    }
    sort(edge.begin(),edge.end(),[&](auto& a,auto& b){
        return a[2] < b[2];
    });
    unionfind uf(n);
    vector<pii> qs(q);
    for (int i = 0;i < q;i++) 
    {
        cin >> qs[i].first;
        qs[i].second = i;
    } 
    int i = 0;
    sort(qs.begin(),qs.end(),[&](auto& a,auto& b) {
        return a.first < b.first;
    });
    vector<ll> ans(q);
    for (auto& [x,id] : qs) 
    {
        while (i < m && edge[i][2] <= x) 
        {
            int u = edge[i][0],v = edge[i][1];
            uf.merge(u,v);
            i++;
        }
        ans[id] = uf.get_ans();
    }
    for (ll x : ans) cout << x << " ";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();


    return 0;
}