#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    int N = 3 * n;
    vvt a(N,vt(N));
    for (int i = 0;i < N;i++) 
    {
        for (int j = 0;j < N;j++)
        {
            cin >> a[i][j];
        }
    }
    
    vll dp(1 << N,LLONG_MIN / 2);
    dp[0] = 0;
    for (int mask = 0;mask < 1 << N;mask++)
    {
        if (dp[mask] == LLONG_MIN / 2) continue;
        int i = 0;
        while (mask >> i & 1) i++;
        for (int j = i + 1;j < N;j++)
        {
            if (mask >> j & 1) continue;
            for (int k = j + 1;k < N;k++)
            {
                if (mask >> k & 1) continue;
                int nmask = mask | 1 << i | 1 << j | 1 << k;
                dp[nmask] = max(dp[nmask],dp[mask] + a[i][j] + a[i][k] + a[j][k]);
            }
        }
    }
    cout << dp[(1 << N) - 1] << endl;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}