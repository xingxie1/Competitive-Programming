#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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
    int n;
    cin >> n;
    vvt g(n);
    map<pii,int> p;
    for (int i = 1;i < n;i++) 
    {
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        p[{u,v}] = i - 1;
        p[{v,u}] = i - 1;
    }
    vt a = {2,3};
    int j = 0;
    vt ans(n - 1);
    queue<int> q;
    vt vis(n);
    for (int i = 0;i < n;i++) 
    {
        if (g[i].size() == 1) 
        {
            q.push(i);
            vis[i] = 1;
            break;
        }
    }
    while (!q.empty()) 
    {
        auto x = q.front();
        q.pop();
        if (g[x].size() >= 3) 
        {
            cout << -1 << endl;
            return ;
        }
        for (int y : g[x]) 
        {
            if (vis[y]) continue;
            q.push(y);
            vis[y] = 1;
            int id = p[{x,y}];
            ans[id] = a[j++];
            j %= 2;
        }
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}