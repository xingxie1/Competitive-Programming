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
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    int B = sqrt(n / 5);
    auto bel = [&](int x) 
    {
        return (x - 1) / B;
    };
    vvt dp(B,vt(n + 1));
    for (int k = 1;k < B;k++)
    {
        for (int i = n;i >= 1;i--)
        {
            int to = i + a[i] + k;
            if (to > n) 
            {
                dp[k][i] = 1;
            }
            else 
            {
                dp[k][i] = dp[k][to] + 1;
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int p,k;
        cin >> p >> k;
        int ans = 0;
        if (k >= B)
        {
            while (p <= n) 
            {
                ans++;
                p += a[p] + k;
            }
        }
        else 
        {
            ans = dp[k][p];
        }
        cout << ans << endl;
    }
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