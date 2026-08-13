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

void solve()
{
    int n,MOD;
    cin >> n >> MOD;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt pre(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] ^ a[i];

    vvt mx(n + 1,vt(4096,-1)); // 前i个数,最后一段xor <= x 的最大段数
    vvll cnt(n + 1,vll(4096)); //方案数
    for (int x = 0;x < 4096;x++) 
    {
        mx[0][x] = 0;
        cnt[0][x] = 1 % MOD;
    }
    for (int i = 1;i <= n;i++) 
    {
        vt dp(4096,-1);
        vll ways(4096);
        for (int j = 0;j < i;j++) 
        {
            int x = pre[i] ^ pre[j];
            int pmx = mx[j][x];
            ll pcnt = cnt[j][x];
            if (pmx == -1) continue;
            int now = pmx + 1;
            if (now > dp[x]) 
            {
                dp[x] = now;
                ways[x] = pcnt;
            }
            else if (now == dp[x]) 
            {
                ways[x] = (ways[x] + pcnt) % MOD;
            }
        }
        int best = -1;
        ll num = 0;
        for (int x = 0;x < 4096;x++) 
        {
            if (dp[x] > best)
            {
                best = dp[x];
                num = ways[x];
            }
            else if (dp[x] == best && best != -1)
            {
                num = (num + ways[x]) % MOD;
            }
            mx[i][x] = best;
            cnt[i][x] = num;
        }
    }
    cout << mx[n][4095] << " " << cnt[n][4095] << endl;
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