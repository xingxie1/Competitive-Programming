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
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int u = 0,d = n - 1;
    int l = 0,r = m - 1;
    while (1) 
    {
        int fff = 0;
        while (u <= d) 
        {
            int f = 1;
            for (int j = l;j <= r;j++) 
            {
                if (a[u][j] == '#') 
                {
                    f = 0;
                    break;
                }
            }
            if (!f) break;
            u++;
            fff = 1;
        }
        while (u <= d) 
        {
            int f = 1;
            for (int j = l;j <= r;j++) 
            {
                if (a[d][j] == '#') 
                {
                    f = 0;
                    break;
                }
            }
            if (!f) break;
            fff = 1;
            d--;
        }
        while (l <= r) 
        {
            int f = 1;
            for (int i = u;i <= d;i++) 
            {
                if (a[i][l] == '#') 
                {
                    f = 0;
                    break;
                }
            }
            if (!f) break;
            fff = 1;
            l++;
        }
        while (l <= r) 
        {
            int f = 1;
            for (int i = u;i <= d;i++) 
            {
                if (a[i][r] == '#') 
                {
                    f = 0;
                    break;
                }
            }
            if (!f) break;
            fff = 1;
            r--;
        }
        if (!fff) break;
    }
    for (int i = u;i <= d;i++) 
    {
        for (int j = l;j <= r;j++) 
        {
            cout << a[i][j];
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