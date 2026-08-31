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
    vvt a(n,vt(3));
    for (int i = 0;i < n;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        a[i] = {u,v,w};
    }
    vvt g(n);
    for (int i = 0;i < n;i++)
    {
        ll x1 = a[i][0],y1 = a[i][1],r1 = a[i][2];
        for (int j = i + 1;j < n;j++)
        {
            ll x2 = a[j][0],y2 = a[j][1],r2 = a[j][2];
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == (r1 + r2) * (r1 + r2)) 
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    queue<int> q;
    vt color(n,-1);
    for (int i = 0;i < n;i++)
    {
        if (color[i] != -1) continue;
        color[i] = 0;
        q.push(i);
        int f = 1;
        vt cnt = {1,0};
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y : g[x])
            {
                if (color[y] == -1) 
                {
                    color[y] = color[x] ^ 1;
                    cnt[color[y]]++;
                    q.push(y);
                }
                else if (color[y] == color[x])
                {
                    f = 0;
                } 
            }
        }
        if (f && cnt[0] != cnt[1]) 
        {
            YES;
            return ;
        }
    }
    NO;
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