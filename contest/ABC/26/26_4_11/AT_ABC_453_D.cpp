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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;   
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<vvt> vis(n,vvt(m,vt(4)));
    queue<tuple<int,int,int>> q;
    pii end;
    pii st;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == 'S') 
            {
                q.push({i,j,0});
                q.push({i,j,1});
                q.push({i,j,2});
                q.push({i,j,3});
                vis[i][j][0] = 1;
                vis[i][j][1] = 1;
                vis[i][j][2] = 1;
                vis[i][j][3] = 1;
                st = {i,j};
            } 
            if (a[i][j] == 'G') end = {i,j};
        }
    }
    vvt dd = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vvt> pre(n,vvt(m,vt(4,-1)));
    while (!q.empty())
    {
        auto [x,y,dir] = q.front();
        q.pop();
        if (pair{x,y} == end) break;
        for (int i = 0;i < 4;i++)
        {
            int nx = x + dd[i][0],ny = dd[i][1] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny][i] || a[nx][ny] == '#') continue;
            if (a[x][y] == 'o' && i != dir) continue;
            if (a[x][y] == 'x' && i == dir) continue;
            q.push({nx,ny,i});
            pre[nx][ny][i] = dir;
            vis[nx][ny][i] = 1;
        }
    }
    int x = end.fi,y = end.se;
    int f = -1;
    for (int i = 0;i < 4;i++) 
    {
        if (vis[x][y][i]) 
        {
            f = i;
            break;
        }
    }
    if (f == -1) 
    {
        cout << "No" << endl;
        return ;
    }
    string ans;
    int d = f;
    vector<char> DIR = {'U','D','L','R'};
    while (x != st.fi || y != st.se)
    {
        int nd = pre[x][y][d];
        int nx = x - dd[d][0],ny = y - dd[d][1];
        ans += DIR[d];
        d = nd;
        x = nx;
        y = ny;
    }
    ranges::reverse(ans);
    cout << "Yes" << endl;
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


