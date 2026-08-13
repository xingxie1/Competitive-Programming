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
    vt b = a;
    ranges::sort(b);
    int mid = b[n / 2];
    vt pre1(n + 1),pre2(n + 1);
    for (int i = 0;i < n;i++) 
    {
        int xx = 0,yy = 0;
        if (a[i] <= mid) xx = 1;
        else xx = -1;
        if (a[i] >= mid) yy = 1;
        else yy = -1;
        pre1[i + 1] = pre1[i] + xx;
        pre2[i + 1] = pre2[i] + yy;
    }
    // for (int x : pre1) cout << x << " ";
    // cout << endl;
    // for (int x : pre2) cout << x << " ";
    // cout << endl;
    vt dp(n + 1,-1);
    dp[0] = 0;
    for (int i = 1;i <= n;i++) 
    {
        for (int j = 0;j < i;j++) 
        {
            if (i % 2 != j % 2 && dp[j] != -1 && pre1[i] - pre1[j] > 0 && pre2[i] - pre2[j] > 0) dp[i] = max(dp[i],dp[j] + 1);
        }
    }
    // for (int x : dp) cout << x << " ";
    // cout << endl;
    cout << dp[n] << endl;

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