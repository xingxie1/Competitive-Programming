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
    vt p(n),q(n),w(n);
    int ans = 0;
    for (int i= 0;i < n;i++) cin >> p[i] >> q[i] >> w[i];
    for (int i = 0;i < n;i++)
    {
        int need = (m * p[i] + q[i] - 1) / q[i];
        if (w[i] < need) ans += need - w[i];
    }
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