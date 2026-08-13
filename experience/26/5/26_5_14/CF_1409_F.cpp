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
    int n,k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    char x = t[0],y = t[1];
    if (x == y) 
    {
        int cnt = count(s.begin(),s.end(),x);
        cnt += min(n - cnt,k);
        cout << 1LL * cnt * (cnt - 1) / 2 << endl;
        return ;
    }
    vvll dp(k + 1,vll(n + 1,LLONG_MIN));
    dp[0][0] = 0;
    for (int i = 0;i < n;i++) 
    {
        vvll ndp(k + 1,vll(n + 1,LLONG_MIN));
        for (int j = 0;j <= k;j++) 
        {
            for (int cnt = 0;cnt <= n;cnt++)
            {
                if (dp[j][cnt] == LLONG_MIN) continue;
                
                if (s[i] == x) 
                {
                    ndp[j][cnt + 1] = max(ndp[j][cnt + 1], dp[j][cnt]);
                }
                else if (s[i] == y) 
                {
                    ndp[j][cnt] = max(ndp[j][cnt],dp[j][cnt] + cnt);
                }
                else 
                {
                    ndp[j][cnt] = max(dp[j][cnt],ndp[j][cnt]);
                }

                if (j + 1 <= k && s[i] != x) 
                {
                    ndp[j + 1][cnt + 1] = max(ndp[j + 1][cnt + 1], dp[j][cnt]);
                }
                if (j + 1 <= k && s[i] != y) 
                {
                    ndp[j + 1][cnt] = max(ndp[j + 1][cnt],dp[j][cnt] + cnt);
                }

            }
        }
        dp = ndp;
    }
    ll ans = 0;
    for (int i = 0;i <= k;i++) 
    {
        for (ll x : dp[i]) ans = max(ans,x);
    }
    cout << ans << endl;
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