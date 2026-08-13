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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt vis(n + 1,vt(n + 1));
    vt used(n + 1);
    vpii ans;
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        used[x] = 1;
        for (int y = x + 1;y <= n;y++)
        {
            auto it1 = find(a.begin(),a.end(),x) - a.begin();
            auto it2 = find(a.begin(),a.end(),y) - a.begin();
            if (it1 < it2 && !vis[y][x])
            {
                ans.push_back({y,x});
                vis[y][x] = 1;
            }
        }
        for (int y = n;y >= x + 1;y--)
        {
            auto it1 = find(a.begin(),a.end(),x) - a.begin();
            auto it2 = find(a.begin(),a.end(),y) - a.begin();
            if (it1 < it2 && !vis[x][y])
            {
                ans.push_back({x,y});
                vis[x][y] = 1;
            }
        }

        for (int y = x - 1;y >= 1;y--)
        {
            if (!vis[x][y] && !used[y])
            {
                vis[x][y] = 1;
                ans.push_back({x,y});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto& [l,r] : ans) cout << l << " " << r << endl;

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