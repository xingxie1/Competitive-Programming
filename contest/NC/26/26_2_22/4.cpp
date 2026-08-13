#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll suf(n + 1),odd(n + 1);
    for (int i = n - 1;i >= 0;i--)
    {
        suf[i] = suf[i + 1] + a[i] / 2;
        odd[i] = odd[i + 1] + a[i] % 2;
    }
    ll ans = 0;
    for (int i = 0;i < n;i++)
    {
        ans += 1LL * a[i] / 2 * (n - i - 1);
        ans += suf[i + 1];
        if (a[i] % 2)
        {
            ans += odd[i + 1];
        }
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