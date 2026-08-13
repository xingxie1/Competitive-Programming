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

void solve()
{
    int n,k;
    cin >> n >> k;
    int ans = -1;
    auto bfs = [&]()
    {
        queue<pair<int,int>> q;
        map<int,int> vis;
        q.emplace(n,0);
        while (!q.empty())
        {
            auto [x,c] = q.front();
            q.pop();
            vis[x]++;
            if (x == k) 
            {
                ans = c;
                break;
            }
            if (!vis.count(x / 2))
            {
                q.emplace(x / 2,c + 1);
                vis[x / 2]++;
            }
                
            if (!vis.count((x + 1) / 2))
                q.emplace((x + 1) / 2,c + 1);
        }
    };
    bfs();
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