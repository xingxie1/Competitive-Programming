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
    int n;
    cin >> n;
    vt s(n),fa(n,-1),a(n);
    vvt g(n);
    for (int i = 1;i < n;i++)
    {
        int u;
        cin >> u;
        u--;
        fa[i] = u;
        g[i].push_back(u);
        g[u].push_back(i);
    }
    for (int i = 0;i < n;i++) cin >> s[i];
    vt vis(n);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int x = q.front();
            q.pop();
            int mn = INT_MAX;
            if (s[x] == -1) 
            {
                for (int y : g[x])
                {
                    if (!vis[y])
                    {
                        vis[y] = 1;
                        q.push(y);
                        mn = min(mn,s[y]);
                        if (s[y] < s[fa[x]]) 
                        {
                            cout << -1 << endl;
                            return ;
                        }
                    }
                }
                if (mn == INT_MAX) 
                {
                    a[x] = 0;
                }
                else 
                {
                    a[x] = mn - s[fa[x]];
                    s[x] = s[fa[x]] + a[x];
                }
            }
            else 
            {
                for (int y : g[x])
                {
                    if (!vis[y])
                    {
                        vis[y] = 1;
                        q.push(y);
                    }
                }
                if (fa[x] != -1) a[x] = s[x] - s[fa[x]];
                else a[x] = s[x];
            }

        }
    }
    ll ans = 0;
    for (int x : a) ans += x;
    cout << ans << endl;
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