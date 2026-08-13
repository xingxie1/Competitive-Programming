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
    int n,m;
    cin >> n >> m;
    ll ans = 0;
    if (n == 1 || m == 1) ans = 1;
    else if (n <= 2 && m <= 2)
    {
        ans = 1;
    }
    else if (n == 2 || m == 2)
    {
        int mx = max(m,n);
        ans = (mx + 1) / 2;
    }
    else if (n == 3 && m == 3) ans = 8;
    else ans = 1LL * n * m;

    cout << ans;
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