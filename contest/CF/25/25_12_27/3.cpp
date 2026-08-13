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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll pre(n + 1),suf(n + 1);
    for (int i = n - 1;i >= 0;i--)
    {
        suf[i] = suf[i + 1] - a[i];
    }
    pre[1] = a[0];
    for (int i = 1;i < n;i++)
    {
        pre[i + 1] = pre[i] + max(a[i],-a[i]);
    }
    ll ans = LLONG_MIN;
    for (int i = 0;i < n;i++)
    {
        ans = max(ans,pre[i] + suf[i + 1]);
    }
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