#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vvt g(n);
    vt deg(n);
    vt has(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        if (has[u] && has[v]) continue;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[v]++;
    }
    for (int i = 0;i < n;i++) 
    {
        ranges::sort(g[i]);
    }
    pqueue<int,vt,greater<>> q;
    vt ans;
    for (int i = 0;i < n;i++) 
    {
        if (!deg[i]) 
        {
            q.push(i);
        }
    }
    while (!q.empty()) 
    {
        int x = q.top();
        q.pop();
        ans.push_back(x);
        for (int y : g[x]) 
        {
            deg[y]--;
            if (!deg[y]) 
            {
                q.push(y);
            }
        }
    }
    if (ans.size() < n) 
    {
        cout << -1 << endl;
        return ;
    }
    for (int x : ans) cout << x + 1 << " ";
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