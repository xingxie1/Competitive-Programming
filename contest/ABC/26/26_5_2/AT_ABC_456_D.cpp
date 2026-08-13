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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vll dp(3);
    for (char c : s)
    {
        if (c == 'a') dp[0] = (dp[0] + dp[1] + dp[2] + 1) % MOD;
        else if (c == 'b') dp[1] = (dp[0] + dp[1] + dp[2] + 1) % MOD;
        else if (c == 'c') dp[2] = (dp[0] + dp[1] + dp[2] + 1) % MOD;
        // cout << dp[0] << " " << dp[1] << " " << dp[2] << endl;
    }
    cout << (dp[0] + dp[1] + dp[2]) % MOD;

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