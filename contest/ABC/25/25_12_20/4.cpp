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
    int n,m;
    cin >> n >> m;
    vt a(n),b(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll sum = 0;
    vll pre(n + 1);
    for (int i = 0;i < n;i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }
    for (int j = 0;j < m;j++)
    {
        ll s1 = 0;
        int i = lower_bound(a.begin(),a.end(),b[j]) - a.begin();
        sum = (sum + (pre[n] - 2LL * pre[i]) % mod) % mod + mod;
        sum = (sum + (1LL * (2 * i - n) * b[j] + mod) % mod) % mod;
        sum = (sum + mod) % mod;

    }
    cout << sum % mod;

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