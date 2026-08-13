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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    int n, x;
    cin >> n >> x;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n == 1)
    {
        cout << max(a[0],x) - 1 << endl;
        return ;
    }
    int mn = ranges::min(a);
    int mx = ranges::max(a);
    ll ans = 0;
    for (int i = 0;i < n - 1;i++) ans += abs(a[i] - a[i + 1]);
    if (mn > 1)
    {
        ans += min({a[0] - 1,a[n - 1] - 1,2 * (mn - 1)});
    }
    if (x > mx)
    {
        ans += min({x - a[0],x - a[n - 1],2 * (x - mx)});
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