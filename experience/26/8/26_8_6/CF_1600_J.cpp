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
    vvt g(n * m);
    vvt d = {{0,-1},{1,0},{0,1},{-1,0}};
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            int x;
            cin >> x;
            // cout << "i : " <<  i << " j : " << j << endl;
            for (int b = 0;b < 4;b++)
            {
                if (x >> b & 1) continue;
                int ni = i + d[b][0],nj = j + d[b][1];
                g[i * m + j].push_back(ni * m + nj);
                // cout << ni << " " << nj << endl;
            }
        }
    }
    vt vis(n * m);
    vt a;
    queue<int> q;
    for (int id = 0;id < n * m;id++)
    {
        if (vis[id]) continue;
        q.push(id);
        vis[id] = 1;
        int cnt = 1;
        while (!q.empty())
        {
            int ii = q.front();
            q.pop();
            for (int jj : g[ii])
            {
                if (!vis[jj]) 
                {
                    q.push(jj);
                    vis[jj] = 1;
                    cnt++;
                }
            }
        }
        a.push_back(cnt);
    }
    ranges::sort(a,{},[&](auto& x){return -x;});
    for (int x : a) cout << x << " ";
    cout << endl;
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