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
    vpll a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    ll sum = 0;
    ranges::sort(a);
    vpll b;
    for (int i = 0;i < n;i++) 
    {
        int j = i;
        ll cnt = 0;
        while (j < n && a[j].fi == a[i].fi) 
        {
            cnt += a[j].se;
            j++;
        }
        b.push_back({a[i].fi,cnt});
        i = j - 1;
    }
    int m = b.size();
    int l = 0,r = m - 1;
    a = b;
    ll ans = 0;
    while (l < r)
    {
        if (a[l].se < a[r].se) 
        {
            ans += 1LL * (a[l].se) * (a[r].fi - a[l].fi);
            a[r].se -= a[l].se;
            l++;
        }
        else if (a[l].se == a[r].se) 
        {
            ans += 1LL * (a[l].se) * (a[r].fi - a[l].fi);
            l++;
            r--;
        }
        else 
        {
            ans += 1LL * (a[r].se) * (a[r].fi - a[l].fi);
            a[l].se -= a[r].se;
            r--;
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