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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    ll n,a,b;
    cin >> n >> a >> b;
    auto cal = [&](ll k)
    {
        if (k < 0 || k * 7 > n) return 0LL;
        ll sum = k * a,res = n - 7 * k;
        sum += min(k,res) * b;
        res -= min(k,res);
        sum += res / 2 * b;
        return sum;
    };
    ll ans = cal(0);
    for (ll k = n / 7 - 2;k <= n / 7 + 2;k++) ans = max(ans,cal(k));
    for (ll k = n / 8 - 2;k <= n / 8 + 2;k++) ans = max(ans,cal(k));
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