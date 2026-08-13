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

    int cnt0 = 0,cnt1 = 0;
    for (int i = 0;i < n;i++)
    {
        int flag = 1;
        for (int j = 0;j < 2 * n;j++)
        {
            if (b[(i + j) % n] <= a[j % n])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cnt0++;
        }
    }
    for (int i = 0;i < n;i++)
    {
        int flag = 1;
        for (int j = 0;j < 2 * n;j++)
        {
            if (c[(i + j) % n] <= b[j % n])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cnt1++;
        }
    }
    ll ans = 1LL * cnt0 * cnt1 * n;
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