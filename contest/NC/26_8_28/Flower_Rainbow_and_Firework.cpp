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
    int n,d,k;
    cin >> n >> d >> k;
    if (k == 1) 
    {
        if (n == 2) 
        {
            cout << "1 2" << endl;
        }
        else cout << -1 << endl;
        return ;
    }
    if (n == 2) 
    {
        cout << "1 2" << endl;
        return ;
    }
    vvt e,g(n);
    int id = 0;
    vt dis(n),a,vis(n);
    a.push_back(0);
    while (e.size() < n - 1 && e.size() < d) 
    {
        if (id == n - 1) break;
        g[id].push_back(id + 1);
        g[id + 1].push_back(id);
        e.push_back({id,id + 1});
        a.push_back(id + 1);
        id++;
    }
    id++;
    for (int i = 1;i < a.size() - 1;i++) 
    {
        dis[i] = max(i,(int)a.size() - i - 1);
    }
    queue<int> q;
    for (int i = 1;i < a.size() - 1;i++) 
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (e.size() == n - 1) break;
        if (id >= n) break;
        while (g[x].size() < k && dis[x] < d && e.size() < n - 1) 
        {
            if (id >= n) break;
            g[x].push_back(id);
            g[id].push_back(x);
            dis[id] = dis[x] + 1;
            e.push_back({x,id});
            q.push(id);
            id++;
        }
    }
    for (int x : dis) 
    {
        if (x > d) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    for (int i = 0;i < n;i++) 
    {
        if (g[i].size() > k) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    for (int i = 0;i < e.size();i++)
    {
        if (e[i][0] > n - 1 || e[i][1] > n - 1) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    if (e.size() != n - 1) 
    {
        cout << -1 << endl;
        return ;
    }
    for (int i = 0;i < e.size();i++) cout << e[i][0] + 1 << " " << e[i][1] + 1 << endl;

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