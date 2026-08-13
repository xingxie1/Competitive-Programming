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
    vt h(n);
    for (int i = 0;i < n;i++) cin >> h[i];
    ll l = 0,r = LLONG_MAX / 2;
    auto check = [&](ll m) 
    {
        vt a = h;
        vll d(n);
        for (int i = n - 1;i >= 2;i--)
        {
            ll x = a[i] + d[i];
            if (x < m) return false;
            if (d[i] >= m) 
            {
                ll r = a[i] / 3;
                d[i - 2] += 2 * r;
                d[i - 1] += r;
            }
            else 
            {
                ll r = (a[i] - (m - d[i])) / 3;
                d[i - 2] += 2 * r;
                d[i - 1] += r;
            }
        }
        for (int i = 1;i >= 0;i--) 
        {
            ll x = a[i] + d[i];
            if (x < m) return false;
        }
        return true;
    };
    while (l + 1 < r)
    {
        ll m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << endl;
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