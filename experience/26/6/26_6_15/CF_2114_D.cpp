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
    vpii a(n),b(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].fi >> a[i].se;
        b[i].fi = a[i].se;
        b[i].se = a[i].fi;
    }
    auto f = [&](vpii& a) 
    {
        ranges::sort(a);
        vt suf1(n + 1),suf2(n + 1,INT_MAX);
        for (int i = n - 1;i >= 0;i--) 
        {
            suf1[i] = max(suf1[i + 1],a[i].se);
            suf2[i] = min(suf2[i + 1],a[i].se);
        }
        int premx = 0,premn = INT_MAX / 2;
        ll ans = 0,mx = 0,mn = INT_MAX;
        for (int i = 0;i < n;i++)
        {
            mx = max(mx,1LL * a[i].se);
            mn = min(mn,1LL * a[i].se);
        }
        ans = 1LL * (mx - mn + 1) * (a[n - 1].fi - a[0].fi + 1);
        if (n == 1) 
        {
            return ans;
        }
        for (int i = 0;i < n;i++)
        {
            int mx = max(premx,suf1[i + 1]);
            int mn = min(premn,suf2[i + 1]);
            ll sum = 1LL * (mx - mn + 1) * (a[n - 1].fi - a[0].fi + 1);
            if (i == n - 1) sum = 1LL * (mx - mn + 1) * (a[n - 2].fi - a[0].fi + 1);
            if (i == 0) sum = 1LL * (mx - mn + 1) * (a[n - 1].fi - a[1].fi + 1);
            if (sum < n) 
            {
                if (i == n - 1) sum += min(a[n - 2].fi - a[0].fi + 1,mx - mn + 1);
                else if (i == 0) sum += min(a[n - 1].fi - a[1].fi + 1,mx - mn + 1);
                else sum += min(a[n - 1].fi - a[0].fi + 1,mx - mn + 1);
            }
            ans = min(ans,sum);
            premx = max(a[i].se,premx);
            premn = min(a[i].se,premn);
        }
        return ans;
    };
    cout << min(f(a),f(b)) << endl;
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