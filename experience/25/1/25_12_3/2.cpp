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
    int n,k;
    cin >> n >> k;
    vt a(k);
    for (int i = 0;i < k;i++) cin >> a[i];
    vt b(k);
    for (int i = 0;i < k;i++) b[i] = n - a[i];
    sort(b.begin(),b.end());
    vll pre(k + 1);
    for (int i = 0;i < k;i++)
    {
        pre[i + 1] = pre[i] + b[i];
    }
    auto it = lower_bound(pre.begin(),pre.end(),1LL * n);
    it--;
    int ans = it - pre.begin();
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