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
    vt pre(n + 1);
    int ans = 0;
    for (int i = 0;i < n;i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }
    for (int i = 0;i <= n;i++)
    {
        for (int j = i + 1;j <= n;j++)
        {
            int sum = pre[j] - pre[i];
            int flag = 1;
            for (int k = i + 1;k <= j;k++)
            {
                if (sum % a[k - 1] == 0) flag = 0;
            }
            if (flag) ans++;
        }
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