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
    int n,m;
    cin >> n >> m;
    vvt a(n,vt(m));
    vector<string> s(n);
    int N = 1 << m;
    vvll g(m,vll(N));//所有通过集合是mask的超级的集合在测试点i上的时间之和
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) cin >> a[i][j];
        cin >> s[i];
        int mask = 0;
        for (int j = 0;j < m;j++) 
        {
            if (s[i][j] == 'A') mask |= 1 << j;
        }
        for (int j = 0;j < m;j++)
        {
            g[j][mask] += a[i][j];
        }
    }
    for (int i = 0;i < m;i++) 
    {
        for (int bit = 0;bit < m;bit++)
        {
            for (int mask = 0;mask < N;mask++)
            {
                if (mask >> bit & 1) continue;
                g[i][mask] += g[i][mask | (1 << bit)];
            }
        }
    }
    ll INF = 1LL << 62;
    vll f(N,INF);//f[s]表示将 s中的测试点放在前面时,最小总耗时
    f[0] = 0;
    for (int mask = 0;mask < N;mask++)
    {
        if (f[mask] == INF) continue;
        for (int i = 0;i < m;i++) 
        {
            if (mask >> i & 1) continue;
            int nxt = mask | (1 << i);
            f[nxt] = min(f[nxt],f[mask] + g[i][mask]);
        }
    }
    cout << f[N - 1] << endl;
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