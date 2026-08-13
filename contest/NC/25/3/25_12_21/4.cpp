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
    sort(a.begin(),a.end());
    map<int,int> cnt;
    ll cnt1 = 0,cnt2 = 0;
    ll ans = 0;
    for (int x : a) cnt[x]++;
    for (auto [x,c] : cnt) 
    {
        if (c >= 2) cnt1++;
        if (c >= 4) cnt2++;
    }
    for (auto [x,c] : cnt)
    {
        int y = x + 1;
        if (c >= 3 && cnt[y] >= 3)
        {
            ll c1 = cnt1;
            ll c2 = cnt2;
            if (c == 3 || c == 4) c1--;
            if (c >= 4 && c < 7) c2--;
            if (cnt[y] == 3 || cnt[y] == 4) c1--;
            if (cnt[y] >= 4 && cnt[y] < 7) c2--;

            ans = ans + 1LL * c1 * (c1 - 1) / 2 % mod;
            ans += c2;
            ans %= mod;
            cout << c1 << " " << c2;
        }
    }
    // cout << ans << endl;
//     cout << cnt1;
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