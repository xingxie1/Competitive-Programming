#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<string> a(n);
    vt r(n,1),c(m,1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        for (int j = 0;j < m;j++) 
        {
            if (a[i][j] == '#') 
            {
                r[i] = 0;
                c[j] = 0;
            }
        }
    }
    queue<pii> q;
    vvt ans(n,vt(m,INT_MAX / 2));
    vvt vis(n,vt(m));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '.' && (r[i] && c[j]))
            {
                q.push({i * m + j,0});
                ans[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    vvt dd = {{-1,0},{1,0},{0,-1},{0,1}};
    while (!q.empty()) 
    {
        auto [id,d] = q.front();
        q.pop();
        int x = id / m,y = id % m;
        for (int i = 0;i < 4;i++)
        {
            int nx = x + dd[i][0];
            int ny = y + dd[i][1];
            if (nx < 0 || ny < 0 || ny >= m || nx >= n || vis[nx][ny] || a[nx][ny] == '#') continue;
            vis[nx][ny] = 1;
            ans[nx][ny] = d + 1;
            q.push({nx * m + ny,d + 1});
        }
    }
    int sum = 0;
    for (int i = 0;i < n;i++)
    {
        // for (int j = 0;j < m;j++)
        // {
        //     if (ans[i][j] <= k)
        //     {
        //         cout << i << " " << j << endl;
        //     }
        // }
        // cout << endl;
        for (int x : ans[i]) 
        {
            sum += (x <= k);
        }
    }
    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}