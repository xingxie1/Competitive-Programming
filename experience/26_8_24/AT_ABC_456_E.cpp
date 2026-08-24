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
    for (int i = 0;i < n;i++) 
    {
        g[i].push_back(i);
    }
    int w;
    cin >> w;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt color(n,vt(w));
    auto dfs = [&](auto&& self,int x,int d)
    {
        color[x][d] = 1;
        int nd = (d + 1) % w;
        for (int y : g[x])
        {
            if (a[y][nd] == 'x') continue;
            if (color[y][nd] == 1)
            {
                return true;
            }
            if (color[y][nd] == 0)
            {
                if (self(self,y,nd)) return true;
            }
        }
        color[x][d] = 2;
        return false;
    };
    for (int i = 0;i < n;i++)
    {
        for (int d = 0;d < w;d++)
        {
            if (a[i][d] == 'x') continue;
            if (dfs(dfs,i,d)) 
            {
                Yes;
                return ;
            }
        }
    }
    No;
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

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// using i128 = __int128_t;
// using vt = vector<int>;
// using vd = vector<double>;
// using vll = vector<long long>;
// using vvt = vector<vector<int>>;
// using vvd = vector<vector<double>>;
// using vvll = vector<vector<long long>>;
// using vvvt = vector<vector<vector<int>>>;
// using vvvll = vector<vector<vector<long long>>>;
// using pii = pair<int,int>;
// using pll = pair<ll,ll>;
// using pdd = pair<double,double>;
// using vpii = vector<pair<int,int>>;
// using vpll = vector<pair<ll,ll>>;
// using vpdd = vector<pair<double,double>>;
// using vvpii = vector<vector<pair<int,int>>>;
// using vvpll = vector<vector<pair<ll,ll>>>;
// using tri = tuple<int,int,int>;
// using trl = tuple<ll,ll,ll>;
// using vtri = vector<tuple<int,int,int>>;
// using vtrl = vector<tuple<ll,ll,ll>>;
// #define YES cout << "YES" << endl
// #define Yes cout << "Yes" << endl
// #define NO cout << "NO" << endl
// #define No cout << "No" << endl
// #define fi first
// #define se second
// #define umap unordered_map
// #define uset unordered_set
// #define pqueue priority_queue
// #define mset multiset
// #define endl '\n'
// //const int MOD = 998244353;
// //const int MOD = (int)1e9+7;

// void solve()
// {
//     int n,m;
//     cin >> n >> m;
//     vvt g(n);
//     for (int i = 0;i < m;i++) 
//     {
//         int u,v;
//         cin >> u >> v;
//         u--;v--;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for (int i = 0;i < n;i++) 
//     {
//         g[i].push_back(i);
//     }
//     int w;
//     cin >> w;
//     vector<string> a(n);
//     for (int i = 0;i < n;i++) cin >> a[i];
//     vvt deg(n,vt(w));
//     for (int d = 0;d < w;d++)
//     {
//         for (int i = 0;i < n;i++)
//         {
//             if (a[i][d] == 'x') continue;
//             int nd = (d + 1) % w;
//             for (int j : g[i])
//             {
//                 if (a[j][nd] == 'o') 
//                 {
//                     deg[j][nd]++;
//                 }
//             }
//         }
//     }
//     queue<pii> q;
//     for (int i = 0;i < n;i++)
//     {
//         for (int d = 0;d < w;d++)
//         {
//             if (deg[i][d] == 0 && a[i][d] == 'o')
//             {
//                 q.push({i,d});
//             }
//         }
//     }
//     while (!q.empty())
//     {
//         auto [x,d] = q.front();
//         q.pop();
//         int nd = (d + 1) % w;
//         for (int y : g[x])
//         {
//             if (a[y][nd] == 'o') 
//             {
//                 deg[y][nd]--;
//                 if (!deg[y][nd]) 
//                 {
//                     q.push({y,nd});
//                 }
//             }
//         }
//     }
//     for (int i = 0;i < n;i++)
//     {
//         for (int d = 0;d < w;d++)
//         {
//             if (a[i][d] == 'x') continue;
//             if (deg[i][d]) 
//             {
//                 Yes;
//                 return ;
//             }
//         }
//     }
//     No;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cout << fixed << setprecision(15);
//     int _ = 1;
//     cin >> _;
//     while (_ --) solve();

//     return 0;
// }