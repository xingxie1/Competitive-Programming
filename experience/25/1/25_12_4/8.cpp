#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,p;
    cin >> n >> p;
    vector<pair<ll,ll>> a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi;
    for (int i = 0;i < n;i++) cin >> a[i].se;
    sort(a.begin(),a.end(),[&](const auto& b,const auto& c)
{
    if (b.se == c.se) return b.fi > c.fi;
    return b.se < c.se;
});

    ll cnt = 0,ans = 0;
    cnt ++;
    ans += p;
    for (int i = 0;i < n;i++)
    {
        if (a[i].se > p) break;
        if (a[i].fi + cnt <= n)
        {
            cnt += a[i].fi;
            ans += 1LL * a[i].fi * a[i].se;
        }
        else 
        {
            ans += (n - cnt) * a[i].se;
            cnt = n;
        }
    }
    ans += 1LL * (n - cnt) * p;
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