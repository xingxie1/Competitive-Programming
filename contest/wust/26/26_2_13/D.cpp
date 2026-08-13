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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    vector g(n,vector<int>(m));
    queue<pii> q;
    for (int i = 0;i < a;i++)
    {
        int x,y;
        cin >> x >> y;
        g[x - 1][y - 1] = 1;
        q.push({x,y});
    }
    map<pii,int> t;
    for (int i = 0;i < b;i++)
    {
        int x,y,tt;
        cin >> x >> y >> tt;
        t[{x,y}] = tt;
        g[x - 1][y - 1] = 2;
    }
    vvt dd = {{-1,0},{1,0},{0,-1},{0,1}};
    int cur = 0;
    while (!q.empty())
    {
        cur++;
        auto [x,y] = q.front();
        q.pop();
        for (int i = 0;i < 4;i++)
        {
            int dx = dd[i][0],dy = dd[i][1];
            if (x + dx > n || y + dy > m || x + dx < 0 || y + dy < 0) continue;
            if (g[dx][dy] == 0) q.push({dx,dy});
            else if (g[dx][dy] == 2) 
            {
                if (cur >= t[{dx,dy}]) 
                {
                    q.push({dx,dy});
                    g[dx][dy] = 1;
                }
            }
        }
    }
    int ans = cur;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            
        }
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