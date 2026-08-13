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
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll b(n - 1);
    for (int i = 0;i + 1 < n;i++)
    {
        b[i] = abs(a[i + 1] - a[i]);
    }
    vpll gcd_left;
    ll ans = 0;
    for (int i = 0;i < n - 1;i++) 
    {
        ll x = b[i];
        for (auto& [gv,_] : gcd_left) 
        {
            gv = gcd(gv,x);
        }
        gcd_left.push_back({x,i});
        int m = 1;
        for (int j = 1;j < gcd_left.size();j++)
        {
            if (gcd_left[j].fi != gcd_left[j - 1].fi)
            {
                gcd_left[m++] = gcd_left[j];
            }
        }
        gcd_left.resize(m);
        for (int k = 0;k < m;k++) 
        {
            auto [gv,left] = gcd_left[k];
            if (gv < 2) continue;
            ll r = k + 1 < m ? gcd_left[k + 1].se - 1 : i;
            ans = max(ans,i - left + 1);
        }
    }
    cout << ans + 1 << endl;
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