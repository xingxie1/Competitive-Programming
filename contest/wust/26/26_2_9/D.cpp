#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    ll x,s,a;
    cin >> x >> a >> s;
    ll ans1 = LLONG_MAX / 2,ans2 = LONG_MAX / 2;
    ll l = -1,r = LLONG_MAX / 2;
    auto check = [&](ll c1)
    {
        if (1LL * c1 * a > x) return 0;
        ll t = x - 1LL * a * c1;
        if (t % s) return 0;
        ll c2 = t / s;
        if (max(c1,c2) < max(ans1,ans2)) 
        {
            ans1 = c1,ans2 = c2;
        }
        if ()
        return 0;
    };
    while (l + 1 < r)
    {
        ll m = l + (r - l) / 2;
        if (check(m))
        {

        }
    }
    for (ll c1 = 0;;c1++)
    {
        if (1LL * c1 * a > x) break;
        ll t = x - 1LL * a * c1;
        if (t % s) continue;
        ll c2 = t / s;
        if (max(c1,c2) < max(ans1,ans2))
        {
            ans1 = c1,ans2 = c2;
        }
    }
    if (ans1 != LLONG_MAX / 2) 
    {
        cout << "Yes" << endl;
        cout << ans1 << " " << ans2 << endl;
    }
    else cout << "N0" << endl;
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