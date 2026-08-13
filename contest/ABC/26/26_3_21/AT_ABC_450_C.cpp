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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    queue<pii> q;
    for (int j = 0;j < m;j++)
    {
        if (a[0][j] == '.') q.push({0,j});
        if (a[n - 1][j] == '.') q.push({n - 1,j});
        a[0][j] = '#';
        a[n - 1][j] = '#';
    }
    for (int i = 0;i < n;i++)
    {
        if (a[i][0] == '.') q.push({i,0});
        if (a[i][m - 1] == '.') q.push({i,m - 1});
        a[i][0] = '#';
        a[i][m - 1] = '#';
    }
    vvt dd = {{-1,0},{1,0},{0,-1},{0,1}};
    auto bfs = [&]()
    {
        while (!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            for (int i = 0;i < 4;i++)
            {
                int nx = x + dd[i][0],ny = y + dd[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (a[nx][ny] == '.')
                {
                    q.push({nx,ny});
                    a[nx][ny] = '#';
                }
            }
        }
    };
    bfs();
    int ans = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '.')
            {
                a[i][j] = '#';
                q.push({i,j});
                bfs();
                ans++;
            }
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