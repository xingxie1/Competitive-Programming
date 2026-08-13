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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int c1 = count(a.begin(),a.end(),1);
    int c2 = count(a.begin(),a.end(),2);
    int c3 = count(a.begin(),a.end(),3);
    vector dp(n + 5,vector(n + 5,vector<double>(n + 5,-1)));
    auto dfs = [&](auto&& self, int i,int j,int k)
    {
        if (i == 0 && j == 0 && k == 0) return 0.0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int s = i + j + k;
        double res = n;
        if (i) res += i * self(self,i - 1,j,k);
        if (j) res += j * self(self,i + 1,j - 1,k);
        if (k) res += k * self(self,i,j + 1,k - 1);

        dp[i][j][k] = res / s;
        return dp[i][j][k];
    };
    dfs(dfs,c1,c2,c3);
    cout << fixed << setprecision(10);
    cout << dp[c1][c2][c3] << endl;
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