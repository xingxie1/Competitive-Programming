#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll ans = ranges::max(a),sum = 0;
    for (int i = 0;i < n;i+=2)
    {
        if (a[i] > 0) sum += a[i];
    }
    if (sum > 0) ans = max(ans,sum);
    sum = 0;
    for (int i = 1;i < n;i += 2)
    {
        if (a[i] > 0) sum += a[i];
    }
    if (sum > 0) ans = max(ans,sum);
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