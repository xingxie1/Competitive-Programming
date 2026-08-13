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
    int N = 3 * n;
    vt x,y,z;
    if (N % 2 == 0)
    {
        int m = (n - 2) / 2;
        int mid = n + m + 1;
        // cout << "mid : " << mid << endl;
        for (int d = 1;d <= m;d++)
        {
            x.push_back(mid + d);
            z.push_back(mid - d);
            y.push_back(2 * d);
        }
        int r = N - m;
        int l = r - 3;
        for (int d = 0;d < m;d++)
        {
            x.push_back(r + d);
            z.push_back(l - d);
            y.push_back(2 * d + 3);
        }
        x.push_back(l + 1);
        z.push_back(1);
        y.push_back(0);
        x.push_back(r - 1);
        z.push_back(mid);
        y.push_back(n);
    }   
    else 
    {
        int m = (n - 1) / 2;
        int mid = (N - 1) / 2;
        for (int d = 1;d <= m;d++)
        {
            x.push_back(mid + d);
            z.push_back(mid - d);
            y.push_back(2 * d);
        }
        int r = N - 1 - m,l = r - 1;
        for (int d = 0;d < m;d++)
        {
            x.push_back(r + d);
            z.push_back(l - d);
            y.push_back(2 * d + 1);
        }
        x.push_back(N - 1);
        z.push_back(mid);
        y.push_back(0);
    }

    for (int i = 0; i < n;i++) cout << x[i] << " " << y[i] << " " << z[i] << endl;
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