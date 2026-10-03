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
    vt deg(n);
    map<int,set<int>> p;
    for (int i = 0;i < m;i++)
    {
        int u,v,w;
        cin >> w >> u >> v;
        u--;v--;
        if (w)
        {
            g[u].push_back(v);
            deg[v]++;
        }
        else 
        {
            p[u].insert(v);
            p[v].insert(u);
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j : p[i])
        {
            if (!p[j].count(i)) 
            {
                g[i].push_back(j);
                deg[j]++;
            }
        }
    }
    queue<int> q;
    vt a(n,-1);
    int val = 1;
    for (int i = 0;i < n;i++)
    {
        if (!deg[i]) 
        {
            q.push(i);
            a[i] = val;
            for (int j : p[i])
            {
                if (p[j].count(i)) 
                {
                    if (a[j] == -1) a[j] = val;
                    else if (a[i] != a[j])
                    {
                        No;
                        return ;
                    }
                }
            }
        }
        else if (a[i] != -1)
        {
            for (int j : p[i])
            {
                if (p[j].count(i)) 
                {
                    if (a[j] == -1) a[j] = a[i];
                    else if (a[i] != a[j])
                    {
                        No;
                        return ;
                    }
                }
            }
        }
    }
    val++;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : g[x])
        {
            deg[y]--;
            if (!deg[y]) 
            {
                q.push(y);
                if (a[y] != -1 && a[y] < a[x]) 
                {
                    No;
                    return ;
                }
                if (p[x].count(y)) a[y] = a[x];
                else a[y] = val++;
                for (int i : p[y])
                {
                    if (p[i].count(y)) 
                    {
                        if (a[i] == -1) a[i] = a[y];
                        else if (a[i] != a[y]) 
                        {
                            No;
                            return ;
                        }
                    }
                }
            }
        }
    }
    Yes;
    for (int x : a) cout << x << " ";
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