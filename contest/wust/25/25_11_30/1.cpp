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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = 0,mx = 0,mn = INT_MAX;
    for (int i = 0;i < n;i++)
    {
        mn = min(mn,a[i]);
        mx = max(mx,a[i]);
    }
    cout << 1 << " " << n << " " << mx - mn;
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