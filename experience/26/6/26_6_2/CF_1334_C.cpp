#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    int n;
    cin >> n;
    vpll a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    vll suf(n + 1);
    suf[n - 1] = a[n - 1].fi;
    for (int i = n - 2;i >= 0;i--) 
    {
        ll a1 = a[i].fi,b1 = a[i].se;
        ll a2 = a[i + 1].fi,b2 = a[i + 1].se;
        suf[i] = suf[i + 1] + a1 - a2 + max(a2 - b1,0LL);
    }
    ll pre = 0;
    ll ans = LLONG_MAX;
    for (int i = 0;i < n;i++) 
    {
        ans = min(ans,suf[i] + pre);
        pre += max(0LL,a[i].fi - a[(i - 1 + n) % n].se);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}