#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
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

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    map<int,int> cnt;
    for (int x : a) cnt[x]++;
    ranges::sort(a);
    a.erase(unique(a.begin(),a.end()),a.end());
    n = a.size();
    ll ans = 0;
    int mex = 0;
    for (int x : a) 
    {
        if (x == mex) mex++;
        else break;
    }
    vll dp(mex + 1,INT_MAX);
    dp[0] = 0;
    for (int i = 0;i <= mex;i++) 
    {
        for (int j = 0;j < i;j++) 
        {
            dp[i] = min(dp[i], dp[j] + 1LL * (cnt[j] - 1) * i + j);
        }
    }
    cout << dp[mex] << endl;
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