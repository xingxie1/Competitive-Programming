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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    vt a(n + 5);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vt dp(n + 5);
    dp[0] = 1;
    for (int i = 1;i <= n;i++) 
    {
        if (i + a[i] <= n)
        {
            dp[i + a[i]] |= dp[i - 1];
        }
        if (i - a[i] >= 1) {
            dp[i] |= dp[i - a[i] - 1];
        }
    }
    if (dp[n]) YES;
    else NO;
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