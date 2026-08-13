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
    vt a(n);
    vt b;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        if (x == 0) b.push_back(i);
        if (x < k) a[i] = -1;
        else if (x == k) a[i] = 0;
        else a[i] = 1;
    }
    vll pre(n + 1);
    unordered_map<int,vector<int>> cnt;
    ll ans = 0;
    for (int i = 0;i < n;i++)
    {
        pre[i + 1] = pre[i] + a[i];
        ll sum = pre[i + 1];
        int last = b[0];
        auto it = lower_bound(cnt[sum].begin(),cnt[sum].end(),last);
        ans += cnt[sum].end() - it;
        cnt[sum].push_back(i);
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