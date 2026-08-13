#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n, t;
    cin >>n >> t;
    if (n == 0)
    {
        cout << t << endl;
        return ;
    }
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll ans = a[0];
    int last = a[0];
    for (int i = 1;i < n;i++)
    {
        if (last + 100 > a[i]) continue;
        ans += (a[i] - last - 100);
        last = a[i];
        // cout << a[i] << endl;
    }
    if (last + 100 <= t) ans += (t - last - 100);
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