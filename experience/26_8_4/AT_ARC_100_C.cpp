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
    int N = 1 << n;
    vt a(N);
    for (int i = 0;i < N;i++) cin >> a[i];
    vvll f(N,vll(2));
    for (int i = 0;i < N;i++) 
    {
        f[i][0] = a[i];
    }
    for (int i = 0;i < n;i++)
    {
        for (int mask = 0;mask < N;mask++)
        {
            if (!(mask >> i & 1)) continue; 
            int x1 = f[mask][0],x2 = f[mask][1];
            int y1 = f[mask ^ (1 << i)][0],y2 = f[mask ^ (1 << i)][1];
            if (y1 >= x1) 
            {
                x2 = x1;
                x1 = y1;
            }
            else if (y1 > x2) 
            {
                x2 = y1;
            }
            if (y2 >= x1) 
            {
                x2 = x1;
                x1 = y2;
            }
            else if (y2 > x2) 
            {
                x2 = y2;
            }
            f[mask][0] = x1;
            f[mask][1] = x2;
        }
    }
    ll ans = 0;
    for (int k = 1;k < N;k++)
    {
        ans = max(ans,f[k][0] + f[k][1]);
        cout << ans << endl;
    }
    
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