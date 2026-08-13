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
    int n;
    cin >> n;
    vt a(n),b(n),c(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    for (int i = 0;i < n;i++) cin >> c[i];
    vll suf1(n + 1),suf2(n + 1);
    vt pre(n + 1);
    vt d(n);
    for (int i = n - 1;i >= 0;i--)
    {
        suf1[i] = suf1[i + 1] + b[i];
        suf2[i] = suf2[i + 1] + c[i];
        d[i] = c[i] - b[i];
        pre[i + 1] = pre[i] + d[i];
    }
    ll p = 0;
    ll ans = 0;
    for (int i = 0;i < n - 2;i++)
    {
        p += a[i];
        ll t = (pre[n] + pre[i]) / 2;
        int j = upper_bound(pre.begin() + i + 1,pre.end(),t) - pre.begin() - 1;
        ll sum = p + suf1[i + 1] - suf1[j] + suf2[j];
        ans = max(ans,sum);
    }
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