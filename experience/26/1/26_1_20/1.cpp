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

struct Edge {
    int x, y, w;
};
vector<Edge> es;
vector<int> fa;
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void solve()
{
    int n,m;
    cin >> n >> m;
    es.resize(m);
    fa.resize(n + 1);
    for (int i = 0;i < m;i++) 
    {
        cin >> es[i].x >> es[i].y >> es[i].w;
    }
    int ans = 0;
    for (int i = 29; i >= 0; i--) 
    {
        // 初始化并查集
        for (int j = 1; j <= n; j++) fa[j] = j;

        int tar = ans >> i;
        for (auto &e : es) 
        {
            if (((e.w >> i) | tar) == tar) 
            {
                fa[find(e.x)] = find(e.y);
            }
        }

        if (find(1) != find(n)) 
        {
            ans |= (1 << i);
        }
    }

    cout << ans << endl;

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