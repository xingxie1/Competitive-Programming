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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt deg(n,vt(m));
    vvt vis(n,vt(m));
    queue<pii> q;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '?') 
            {
                deg[i][j] = 4;
                if (i == 0) deg[i][j]--;
                if (i == n - 1) deg[i][j]--;
                if (j == 0) deg[i][j]--;
                if (j == m - 1) deg[i][j]--;
            }
            else 
            {
                char c = a[i][j];
                deg[i][j] = 1;
                if (c == 'L' && j == 0) deg[i][j]--;
                else if (c == 'R' && j == m - 1) deg[i][j]--;
                else if (c == 'U' && i == 0) deg[i][j]--;
                else if (c == 'D' && i == n - 1) deg[i][j]--;
            }
            if (!deg[i][j]) 
            {
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }
    vvt dd = {{-1,0},{1,0},{0,1},{0,-1}};
    auto dir = [&](int x,int y) -> pii
    {
        int rx = x,ry = y;
        if (a[x][y] == 'L') ry--;
        if (a[x][y] == 'R') ry++;
        if (a[x][y] == 'U') rx--;
        if (a[x][y] == 'D') rx++;
        return {rx,ry};
    };
    auto bfs = [&]()
    {
        while (!q.empty())
        {
            auto [x,y] = q.front();
            // cout << x << " " << y << endl;
            q.pop();
            for (int i = 0;i < 4;i++)
            {
                int dx = dd[i][0],dy = dd[i][1];
                int nx = x + dx,ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (a[nx][ny] == '?') deg[nx][ny]--;
                else if (pair{x,y} == dir(nx,ny)) deg[nx][ny]--;
                if (!deg[nx][ny] && !vis[nx][ny]) 
                {
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        
    };
    bfs();
    int ans = n * m;
    for (int i = 0;i < n;i++)
    {
        for (int x : vis[i]) ans -= x;
    }
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