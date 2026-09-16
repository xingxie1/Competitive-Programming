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

int MOD;
const int MX = 200001;
ll F[MX]; // F[i] = i!
ll INV_F[MX]; // INV_F[i] = i!^-1 = qpow(i!, MOD-2)

ll qpow(ll a, ll b) 
{
    ll res = 1;
    b %= MOD;
    while (b)
    {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

auto init = [](int MOD)
{
    F[0] = 1;
    for (int i = 1; i < MX; i++) 
    {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) 
    {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
};

// 从 n 个数中选 m 个数的方案数
ll comb(int n, int m) 
{
    return m < 0 || m > n ? 0 : F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}

void solve()
{
    int n,m,p;
    cin >> n >> m >> p;
    MOD = p - 1;
    init(MOD);
    vvt a(n,vt(m)),b(n,vt(m));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) cin >> a[i][j];
    }
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) cin >> b[i][j];
    }
    queue<vt> q;
    vvvt vis(n,vvt(m,vt(MOD)));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            a[i][j] = a[i][j] * qpow(p,qpow(2,b[i][j])) % MOD;
        }
    }
    q.push({0,0,a[0][0],0});
    vis[0][0][a[0][0]] = 1;
    vvt d = {{-1,0},{1,0},{0,-1},{0,1}};
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        int x = f[0],y = f[1],v = f[2],t = f[3];
        if (x == n - 1 && y == m - 1 && v == 0) 
        {
            cout << t << endl;
            return ;
        }
        for (int i = 0;i < 4;i++) 
        {
            int nx = x + d[i][0],ny = y + d[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            int nv = (v + a[nx][ny]) % MOD;
            if (vis[nx][ny][nv]) continue;
            vis[nx][ny][nv] = 1;
            q.push({nx,ny,nv,t + 1});
        }
    }
    cout << -1 << endl;
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