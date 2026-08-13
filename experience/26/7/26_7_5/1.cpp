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
    int n,m;
    cin >> n >> m;
    vvt a(n,vt(m));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) cin >> a[i][j];
    }
    vvt p(1e6 + 1,vt(4,-1));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            int x = a[i][j];
            if (p[x][0] == -1) 
            {
                p[x] = {i,i,j,j};
            }
            else 
            {
                p[x][0] = min(p[x][0],i);
                p[x][1] = max(p[x][1],i);
                p[x][2] = min(p[x][2],j);
                p[x][3] = max(p[x][3],j);
            }
        }
    }
    vvt d(n + 2,vt(m + 2));
    for (int i = 1;i <= 1e6;i++) 
    {
        if (p[i][0] == -1 || (p[i][0] == p[i][1] && p[i][2] == p[i][3])) continue;
        int x1 = p[i][0],y1 = p[i][2],x2 = p[i][1],y2 = p[i][3];
        d[x1][y1]++;
        d[x2 + 1][y2 + 1]++;
        d[x1][y2 + 1]--;
        d[x2 + 1][y1]--;
    }
    vvt sum(n + 1,vt(m + 1));
    int ans = 0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + d[i][j];
            if (sum[i + 1][j + 1] == 0) 
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
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