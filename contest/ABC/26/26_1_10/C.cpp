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
    int n,w;
    cin >> n >> w;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vll pre(n + 1);
    for (int i = 1;i <= n;i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = LLONG_MAX;
    for (int x = 0;x < 2 * w;x++)
    {
        ll sum = 0;
        int dm = 0;
        for (int d = 1;;d++)
        {
            if (d * w - x - 1 > n) break;
            dm = d;
            if (d * w - x - 1 <= 0) continue;
            if (d % 2 == 1)
            {
                if (d != 1) 
                    sum += pre[d * w - x - 1] - pre[(d - 1) * w - x - 1];
                else sum += pre[w - x - 1];
            }
        }
        if (dm % 2 == 0)
        {
            if (dm == 0) continue;
            sum += pre[n] - pre[dm * w - x - 1];
        }
        ans = min(ans,sum);
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