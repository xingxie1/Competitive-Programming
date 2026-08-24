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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a);
    int mx = a.back();
    vt cnt(mx);
    for (int i = 0;i < n;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            cnt[a[j] - a[i]]++;
        }
    }
    vll suf(mx + 1);
    for (int i = mx - 1;i >= 0;i--) suf[i] = suf[i + 1] + cnt[i];
    double ans = 0;
    for (int d1 = 1;d1 <= mx;d1++)
    {
        for (int d2 = 1;d2 <= mx;d2++)
        {
            if (d1 + d2 >= mx - 1) break;
            double p1 = 2.0 * cnt[d1] / (n * (n - 1));
            double p2 = 2.0 * cnt[d2] / (n * (n - 1));
            double p3 = 2.0 * suf[d1 + d2 + 1] / (n * (n - 1));
            ans += p1 * p2 * p3;
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
    // cin >> _;
    while (_ --) solve();

    return 0;
}