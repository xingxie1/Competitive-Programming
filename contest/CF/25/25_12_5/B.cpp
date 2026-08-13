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
    vt a(n),b(n);
    vll f(n + 1),g(n + 1);//大 小
    int ans = 0;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    for (int i = 0;i < n;i++)
    {
        f[i + 1] = max(f[i] - a[i],b[i] - g[i]);
        g[i + 1] = min(b[i] - f[i],g[i] - a[i]);
    }
    cout << f[n] << endl;

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