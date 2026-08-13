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

vector<vector<int>> dd = {{-1,0},{-1,1},{1,-1},{1,-1}};

void bfs(vector<vector<int>>& grid,vector<int>& vis,vector<int>& d1)
{
    int n = grid.size(),m = grid[0].size();
    queue<tuple<int,int,int>> q;
    q.emplace(0,0,0);
    int ans = INT_MAX;
    while (!q.empty())
    {
        auto [x,y,d] = q.front();
        if (x == n - 1 && y == n - 1) 
        {
            ans = min(ans,d);
            break;
        }
        char ch = grid[x][y];
        if (ch >= 'a' && ch <= 'z' && !vis[ch - 'a']) 
        {
            d1[ch - 'a'] = d;
            vis[ch - 'a'] = 1;
        }
        q.pop();
        grid[x][y] = '#';
        for (int i = 0;i < 4;i++)
        {
            int dx = x + dd[i][0],dy = y + dd[i][1];
            char cc = grid[dx][dy];
            if (cc >= 'a' && cc <= 'z' && !vis[cc - 'a'])
            {
                grid[dx][dy] = '#';
                vis[cc - 'a'] = 1;
                continue;
            }
            if (dx >= 0 && dx < n && dy >= 0 && dy < n && grid[dx][dy] != '#')
            {
                q.emplace(dx,dy,d + 1);
            }
        }
    }
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<string> grid2(n);
    for (int i = 0;i < n;i++) cin >> grid[i];
    for (int i = 0;i < n;i++) grid2[i] = grid[i];
    queue<tuple<int,int,int>> q;
    q.emplace(0,0,0);
    vector<int> vis1(26),vis2(26),d1(26,INT_MAX / 2),d2(26,INT_MAX / 2);
    int ans = INT_MAX;
    while (!q.empty())
    {
        auto [x,y,d] = q.front();
        if (x == n - 1 && y == n - 1) 
        {
            ans = min(ans,d);
            break;
        }
        char ch = grid[x][y];
        if (ch >= 'a' && ch <= 'z' && !vis1[ch - 'a']) 
        {
            d1[ch - 'a'] = d;
            vis1[ch - 'a'] = 1;
        }
        q.pop();
        grid[x][y] = '#';
        for (int i = 0;i < 4;i++)
        {
            int dx = x + dd[i][0],dy = y + dd[i][1];
            char cc = grid[dx][dy];
            if (cc >= 'a' && cc <= 'z' && !vis1[cc - 'a'])
            {
                grid[dx][dy] = '#';
                vis1[cc - 'a'] = 1;
                continue;
            }
            if (dx >= 0 && dx < n && dy >= 0 && dy < n && grid[dx][dy] != '#')
            {
                q.emplace(dx,dy,d + 1);
            }
        }
    }
    queue<tuple<int,int,int>> q2;
    q2.emplace(n - 1,m - 1,0);
    while (!q2.empty())
    {
        auto [x,y,d] = q.front();
        if (x == 0 && y == 0) 
        {
            ans = min(ans,d);
            break;
        }
        char ch = grid2[x][y];
        if (ch >= 'a' && ch <= 'z' && !vis2[ch - 'a']) 
        {
            d2[ch - 'a'] = d;
            vis2[ch - 'a'] = 1;
        }
        q2.pop();
        grid2[x][y] = '#';
        for (int i = 0;i < 4;i++)
        {
            int dx = x + dd[i][0],dy = y + dd[i][1];
            char cc = grid2[dx][dy];
            if (cc >= 'a' && cc <= 'z' && !vis2[cc - 'a'])
            {
                grid2[dx][dy] = '#';
                vis2[cc - 'a'] = 1;
                continue;
            }
            if (dx >= 0 && dx < n && dy >= 0 && dy < n && grid2[dx][dy] != '#')
            {
                q2.emplace(dx,dy,d + 1);
            }
        }
    }
    for (int i = 0;i < 26;i++)
    {
        ans = min(ans,d1[i] + d2[i]);
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