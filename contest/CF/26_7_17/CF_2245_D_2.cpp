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
    int n, m;
    cin >> n >> m;
    vt a(n),b(n);
    vvt edge(m);
    for (int i = 0;i < m;i++)
    {
        int o,l,r;
        cin >> o >> l >> r;
        l--;r--;
        if (l == r)
        {
            if (o == 1) b[l] = 1;
            else b[l] = -1;
        }
        edge[i] = {o,l,r};
    }
    ranges::sort(edge,{},[&](auto& e) {
        return pair{e[1],e[2]};
    });
    vvt g(n);
    vt deg(n);
    for (auto& e : edge)
    {
        int o = e[0],i = e[1],j = e[2];
        if (o == 1) 
        {
            if (b[i] == 0 && b[j] == 0) 
            {
                b[i] = b[j] = 1;
            }
            else if (b[i] == 0) 
            {
                b[i] = 1;
            }
            else if (b[j] == 0) b[j] = 1;

            if (b[i] > 0 && b[j] < 0)
            {
                g[i].push_back(j);
                deg[j]++;
            }
            else if (b[i] < 0 && b[j] > 0) 
            {
                g[j].push_back(i);
                deg[i]++;
            }
            else if (b[i] < 0 && b[j] < 0) 
            {
                NO;
                return ;
            }
        }
        else 
        {
            if (b[i] == 0 && b[j] == 0) 
            {
                b[i] = b[j] = -1;
            }
            else if (b[i] == 0) 
            {
                b[i] = -1;
            }
            else if (b[j] == 0) b[j] = -1;

            if (b[i] > 0 && b[j] < 0)
            {
                g[j].push_back(i);
                deg[i]++;
            }
            else if (b[i] < 0 && b[j] > 0) 
            {
                g[i].push_back(j);
                deg[j]++;
            }
            else if (b[i] > 0 && b[j] > 0) 
            {
                NO;
                return ;
            }
        }
    }
    queue<int> q;
    int x = 1e9;
    for (int i = 0;i < n;i++)
    {
        if (!deg[i]) 
        {
            q.push(i);
            if (b[i] > 0) a[i] = x;
            else a[i] = -x;
            x--;
        }
    }
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        for (auto& j : g[i])
        {
            deg[j]--;
            if (a[i] < 0) 
            {
                if (b[j] < 0) 
                {
                    if (a[j] == 0) a[j] = a[i] + 1;
                    else a[j] = max(a[j],a[i] + 1);
                }
                else 
                {
                    if (a[j] == 0) a[j] = -a[i] - 1;
                    else a[j] = min(a[j],-a[i] - 1);
                }
            }
            else 
            {
                if (b[j] < 0)
                {
                    if (a[j] == 0) a[j] = -a[i] + 1;
                    else a[j] = max(a[j],-a[i] + 1);
                }
                else 
                {
                    if (a[j] == 0) a[j] = a[i] - 1;
                    else a[j] = min(a[j],a[i] - 1);
                }
            }
            if (!deg[j]) q.push(j);
        }
    }
    for (int x : a) 
    {
        if (x == 0) 
        {
            NO;
            return ;
        }
    }
    for (auto& e : edge)
    {
        int o = e[0],i = e[1],j = e[2];
        if (o == 1) 
        {
            if (a[i] + a[j] < 0) 
            {
                NO;
                return ;
            }
        }
        else 
        {
            if (a[i] + a[j] >= 0) 
            {
                NO;
                return ;
            }
        }
    }
    YES;
    for (int x : a) cout << x << " ";
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