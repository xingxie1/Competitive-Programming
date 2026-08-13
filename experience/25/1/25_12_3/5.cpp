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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    ll x = gcd(c,d);
    if (x != 1)
    {
        c /= x;
        d /= x;
    }

    ll t1 = a / c;
    ll t2 = b / d;
    ans = min (t1,t2);

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