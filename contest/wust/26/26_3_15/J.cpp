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
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,p,x;
    cin >> n >> p >> x;
    vt a(n);
    ll sum = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    for (int i = 0;i < n;i++)
    {
        ll nsum = sum - a[i];
        int res = nsum % x;
        int t = (x - res) % x;
        if (t == 0) ans += p / x;
        else if (p >= t) ans += (p - t) / x + 1;
        if (a[i] % x == t && a[i] <= p) ans--;
    }
    cout << ans << endl;
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