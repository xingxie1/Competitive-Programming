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
    ll ans = 0;
    vector<pair<ll,ll>> p;
    for (int i = 0;i < n;i++)
    {
        ll a,b;
        cin >> a >> b;
        if (!a) ans = max(ans,b);
        else
        {
            p.push_back({a,b});
        }
    }
    sort(p.begin(),p.end(),[&](auto& a,auto& b){
        auto [a1,b1] = a;
        auto [a2,b2] = b;
        if (a1 * b2 + b1 != a2 * b1 + b2) return a1 * b2 + b1 < a2 * b1 + b2;
        if (a1 != a2) return a1 < a2;
        if (b1 != b2) return b1 < b2;
        return false;
    });

    for (auto [a,b] : p)
    {
        ans = (ans * a + b) % MOD;
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