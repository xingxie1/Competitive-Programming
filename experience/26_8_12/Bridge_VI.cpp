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
    vt a(2 * n);
    for (int i = 0;i < 2 * n;i++) cin >> a[i];
    int t = a[0] + m;
    int ans1 = 0;
    if (a[1] > t) ans1++;
    for (int i = 2;i < 2 * n;i += 2)
    {
        int mn = min(a[i],a[i + 1]);
        int mx = max(a[i],a[i + 1]);
        int res = m;
        if (mx > t)
        {
            ans1++;
            if (mn > t) ans1++;
        }
        else if (mx == t) 
        {
            mn += res;
            if (mn > t) ans1++;
        }
        else 
        {
            res -= t - mx;
            mn += res;
            if (mn > t) ans1++;
        }
    }
    int ans2 = 0;
    t = a[0];
    if (a[1] + m > a[0]) ans2++;
    for (int i = 2;i < 2 * n;i += 2)
    {
        int mn = min(a[i],a[i + 1]);
        int mx = max(a[i],a[i + 1]);
        int res = m;
        if (mx > t)
        {
            ans2++;
            if (mn + m > t) ans2++;
        }
        else if (mx == t)
        {   
            res--;
            ans2++;
            if (mn + res >= t) ans2++;
        }
        else 
        {
            if (mx + res > t) 
            {
                ans2++;
                res -= (t - mx + 1);
                mn += res;
                if (mn >= t) ans2++;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
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