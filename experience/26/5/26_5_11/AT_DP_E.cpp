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
//const int MOD = (int)1e9+7;

void solve()
{
    int n,w;
    cin >> n >> w;
    vt dp(1e5 + 1,INT_MAX / 2);
    dp[0] = 0;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i] >> b[i];
    for (int i = 0;i < n;i++) 
    {
        for (int j = 1e5;j >= b[i];j--) 
        {
            dp[j] = min(dp[j],dp[j - b[i]] + a[i]);
        }
    }
    for (int j = 1e5;j >= 0;j--) 
    {
        if (dp[j] <= w) 
        {
            cout << j << endl;
            return ;
        }
    }
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