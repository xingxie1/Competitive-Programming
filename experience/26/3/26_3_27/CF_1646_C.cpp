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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    ll n;
    cin >> n;
    ll ret = 2;
    vll a;
    for (ll i = 3;;i++)
    {
        ret *= i;
        if (ret > 1e12) break;
        a.push_back(ret);
    }
    int ans = INT_MAX;
    int m = a.size();
    // cout << m << endl;
    for (int i = 0;i < (1 << m);i++)
    {
        ll s = 0;
        int cnt =0;
        for (int j = 0;j < m;j++)
        {
            if (i >> j & 1) 
            {
                s += a[j];
                cnt++;
            }
        }
        if (s <= n) ans = min(ans,cnt + popcount(1ull * (n - s))); 
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