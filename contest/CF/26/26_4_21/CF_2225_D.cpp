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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    ll n,x;
    cin >> n >> x;
    ll lc0 = 1 + x / 4,rc0 = 1 + (n + 1) / 4 - lc0;
    ll lc1 = (x + 2) / 4,rc1 = (n + 3) / 4 - lc1; 
    lc0 %= MOD;
    lc1 %= MOD;
    rc0 %= MOD;
    rc1 %= MOD;
    ll ans = lc0 * rc0 % MOD;
    ans = (ans + lc1 * rc1) % MOD; 
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