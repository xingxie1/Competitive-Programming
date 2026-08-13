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

ll comb(int x,int a)
{
    if (x == 1) return 1;
    return 1LL * x * (x - 1) / 2;
}
void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    map<int,int> cnt;
    ll ans = 0;
    for (int x : a) 
    {
        cnt[x]++;
    }
    ll s = 1;
    for (int i = 1;i <= cnt.size();i++)
    {
        if (cnt[i] <= 1) break;
        s = s * comb(cnt[i],2) % mod;
        ans += s;
        ans %= mod;
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