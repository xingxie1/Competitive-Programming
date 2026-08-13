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
// #define endl '\n'
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
    queue<int> q;
    vt color(n,-1);
    int f = 1;
    for (int i = 0;i < n;i++)
    {
        if (color[i] != -1) continue;
        q.push(i);
        color[i] = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y : g[x])
            {
                if (color[y] == -1)
                {
                    color[y] = color[x] ^ 1;
                    q.push(y);
                }
                else if (color[y] == color[x]) 
                {
                    f = 0;
                }
            }
        }
    }
    if (!f) 
    {
        cout << "Alice" << endl;
        while (n--)
        {
            cout << "1 2" << endl;
            int x,y;
            cin >> x >> y;
        }
    }
    else 
    {
        vvt p(3);
        for (int i = 0;i < n;i++) 
        {
            p[color[i] + 1].push_back(i + 1);
        }
        cout << "Bob" << endl;
        while (n--)
        {
            int x,y;
            cin >> x >> y;
            if (x == 3) swap(x,y);
            int f = 0;
            if (y == 3) 
            {
                y = 3 - x;
                f = 1;
            }
            if (!p[x].empty()) 
            {
                cout << p[x].back() << " " << x << endl;
                p[x].pop_back();
            }
            else if (!p[y].empty()) 
            {
                cout << p[y].back() << " ";
                if (f == 1) cout << 3 << endl;
                else cout << y << endl;
                p[y].pop_back();
            }
        }
    }
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