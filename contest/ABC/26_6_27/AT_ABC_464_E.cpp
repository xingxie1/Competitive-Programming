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
    int n,m, q;
    cin >> n >> m >> q;
   vvt a(n,vt(m));
   vvt qs(q);
   for (int i = 0;i < q;i++)
   {
        int x,y;
        char c;
        cin >> x >> y >> c;
        int v = c - 'A';
        x--;y--;
        qs[i] = {x,y,v};
   }
   ranges::reverse(qs);
   vvt vis(n,vt(m));
   for (auto & b : qs) 
   {
        int x = b[0],y = b[1],v = b[2];
        for (int i = x;i >= 0;i--) 
        {
            if (vis[i][y]) break;
            for (int j = y;j >= 0;j--)
            {
                if (vis[i][j]) break;
                a[i][j] = v;
                vis[i][j] = 1;
            }
        }
   }
   for (int i = 0;i < n;i++)
   {
        for (int j = 0;j < m;j++) 
        {
            char c = 'A' + a[i][j];
            cout << c;
        }
        cout << endl;
   }
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