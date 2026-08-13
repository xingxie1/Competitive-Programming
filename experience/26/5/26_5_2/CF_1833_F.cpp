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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
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
const int MOD = (int)1e9+7;

ll qpow(ll a, int b) 
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    map<int,int> cnt;
    for (int x : a) cnt[x]++;
    ranges::sort(a);
    a.erase(unique(a.begin(),a.end()),a.end());
    n = a.size();
    vll pre(n + 1,1);
    for (int i = 0;i < n;i++) pre[i + 1] = (pre[i] * cnt[a[i]]) % MOD;
    int l = 0,r = 0;
    ll ans = 0;
    while (r < n)
    {
        while (l < r && a[r] - a[l] >= m) l++;
        if (r - l + 1 == m) 
        {
            ans = (ans + pre[r + 1] * qpow(pre[l],MOD - 2)) % MOD;
            l++;
        }
        r++;
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