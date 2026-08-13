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

int lb(vector<pair<int,int>>& g,int x)
{
    int l = -1,r = g.size();
    while (l + 1 < r)
    {
        int mid = (r + l) / 2;
        if (g[mid].fi > x) r = mid;
        else l = mid;
    }
    return l;
}
void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<int> ans(n);
    vector<pair<int,int>> g;
    g.push_back({1,n});
    for (int i = n - 1;i >= 0;i--)
    {
        ans[i] = g.size();
        int j = lb(g,a[i]);
//         cout << g[j].fi << " " << g[j].se << endl;
        if (g[j].fi == g[j].se) g.erase(g.begin() + j);
        else if (g[j].se == a[i]) g[j].se--;
        else if (g[j].fi == a[i]) g[j].fi++;
        else 
        {
            int l = g[j].fi,r = g[j].se;
            auto it = g.erase(g.begin() + j);
            it = g.insert(it,{a[i] + 1,r});
            it = g.insert(it,{l,a[i] - 1});
        }
//         for (auto [x,y] : g) cout << x << " " << y << " ";
//         cout << endl;
    }
    for (int i = 0;i < n;i++) cout << ans[i] << " ";
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