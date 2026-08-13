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
    vvt g(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = 0;
    int mn = INT_MAX;
    queue<int> q;
    vt color(n,-1);
    for (int i = 0;i < n;i++)
    {
        if (color[i] != -1) continue;
        q.push(i);
        color[i] = 0;
        vt cnt = {1,0};
        int f = 0,sz = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y : g[x])
            {
                if (color[y] == -1) 
                {
                    color[y] = color[x] ^ 1;
                    cnt[color[y]]++;
                    sz++;
                    q.push(y);
                }
                else if (color[x] == color[y]) f = 1;
            }
        }
        if (f) 
        {
            cout << "0 1" << endl;
            return ;
        }
        if (sz == 1) mn = min(mn,3);
        else if (sz == 2) mn = min(mn,2);
        else 
        {
            mn = min(mn,1);
            ans += 1LL * cnt[0] * (cnt[0] - 1) / 2 + 1LL * cnt[1] * (cnt[1] - 1) / 2;
        } 
    }
    if (mn == 3) 
    {
        ans = 1LL * n * (n - 1) * (n - 2) / 6;
    }
    else if (mn == 2) 
    {
        ans = 1LL * (n - 2) * m;
    }
    cout << mn << " " << ans << endl;
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