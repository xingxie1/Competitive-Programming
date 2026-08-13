#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
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
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

int MOD;

void solve()
{
    int n;
    cin >> n >> MOD;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt sum(n + 1);
    for (int i = 0;i < n;i++) sum[i + 1] = sum[i] ^ a[i];
    //[l,r]
    auto query = [&](int l,int r)
    {
        return sum[r] ^ sum[l - 1];
    };
    vt dp(n + 1,INT_MAX);
    vt cnt(n);
    dp[0] = 0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j <= i;j++) 
        {
            int s = query(j + 1,i + 1);
            if (s > dp[j]) 
            {
                dp[i + 1] = min(dp[i + 1],s);
                cnt[i] = max(cnt[i],cnt[j] + 1);
            }
        }
    }
    cout << cnt[n - 1] << endl;



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