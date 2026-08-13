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
    if (n <= 0 || m <= 0) 
    {
        cout << -1 << endl;
        return ;
    }
    vvll a(n,vll(m));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            cin >> a[i][j];
        }
    }
    if (a[0][0] != a[n - 1][m - 1]) 
    {
        cout << -1 << endl;
        return ;
    }
    if (n == 1 && m == 1) 
    {
        cout << 0 << endl;
        return ;
    }
    if (n == 1) 
    {
        vll b;
        for (int i = 0;i < m;i++) b.push_back(a[0][i]);
        ranges::sort(b);
        if (b[0] != b.back()) cout << -1 << endl;
        else cout << 0 << endl;
        return ;
    }
    if (m == 1) 
    {
        vll b;
        for (int i = 0;i < n;i++) b.push_back(a[i][0]);
        ranges::sort(b);
        if (b[0] != b.back()) cout << -1 << endl;
        else cout << 0 << endl;
        return ;
    }

    ll x1 = a[0][0],x2 = a[0][1],x3 = a[1][0];
    ll t = x3 + x2 - x1;
    vvll b(n,vll(m));
    vvll c(n,vll(m));
    ll ans = t - a[0][0];
    // cout << "t : " << t << endl;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            b[i][j] = t - a[i][j];
            c[i][j] = t - a[i][j];
            if (b[i][j] < 0) 
            {
                cout << -1 << endl;
                return ;
            }
        }
    }

    for (int j = 0;j < m - 1;j++)
    {
        b[n - 1][j + 1] -= c[n - 1][j];
        if (b[n - 1][j + 1] < 0) 
            {
                cout << -1 << endl;
                return ;
            }
        for (int i = n - 2;i >= 0;i--)
        {
            if (c[i][j] - b[i + 1][j] < 0) 
            {
                cout << -1 << endl;
                return ;
            }
            b[i][j + 1] -= (c[i][j] - b[i + 1][j]);
            if(b[i][j + 1] < 0) {
                cout << -1 << endl;
                return;
            }
        }
    }
    if (b[0][m - 1] != 0) 
    {
        cout << -1 << endl;
        return ;
    }
    for (int i = 1;i < n;i++)
    {
        if (b[i][m - 1] != c[i - 1][m - 1]) 
        {
            cout << -1 << endl;
            return ;
        }   
    }
    cout << ans << endl;
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