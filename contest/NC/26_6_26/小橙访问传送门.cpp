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
    vt a(n),b(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    ranges::sort(a);
    ranges::sort(b);
    ll ans = LLONG_MAX / 2;
    auto it1 = ranges::lower_bound(a,0);
    auto it2 = it1;
    it2--;
    ll mn1 = LLONG_MAX;
    if (it1 != a.end()) mn1 = min(mn1,1LL * (*it1));
    if (it1 != a.begin()) mn1 = min(mn1,1LL * abs(*it2));
    it1 = ranges::lower_bound(b,0);
    it2 = it1;
    it2--;
    ll mn2 = LLONG_MAX;
    if (it1 != b.end()) mn2 = min(mn2,1LL * (*it1));
    if (it1 != b.begin()) mn2 = min(mn2,1LL * abs(*it2));
    for (int i = 0;i < n;i++) 
    {
        auto it = ranges::lower_bound(b,a[i]);
        ll mn = LLONG_MAX;
        if (it != b.end()) mn = (*it - a[i]);
        if (it != b.begin()) 
        {
            it--;
            mn = min(mn,1LL * abs(a[i] - *it));
        }
        ans = min({ans,1LL * mn1 + mn + mn2,2LL * mn1 + 2LL * mn,2LL * mn2 + 2LL * mn});
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