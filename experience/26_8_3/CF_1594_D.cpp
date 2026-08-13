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
    vvpii g(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        string s;
        cin >> u >> v >> s;
        u--;v--;
        int x = 0;
        if (s == "crewmate") x = 1;
        g[u].push_back({v,x});
        g[v].push_back({u,x});
    }
    vt color(n,-1);
    int ans = 0;
    for (int i = 0;i < n;i++)
    {
        if (color[i] != -1) continue;
        color[i] = 0;
        queue<int> q;
        q.push(i);
        vt cnt = {1,0};
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto& [y,w] : g[x])
            {
                int cy = color[x] ^ (1 - w);
                if (color[y] == -1) 
                {
                    color[y] = cy;
                    cnt[cy]++;
                    q.push(y);
                }
                else if (color[y] != cy) 
                {
                    cout << -1 << endl;
                    return ;
                }
            }
        }
        ans += max(cnt[0],cnt[1]);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}