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
    vvt a(n,vt(3));
    int mx = 0;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i][2] >> a[i][0] >> a[i][1];
        mx = max(mx,a[i][2] + a[i][0]);
    }
    vvt dp(n + 1,vt(1001));
    for (int x = 0;x <= 1000;x++) dp[n][x] = x;
    for (int i = n - 1;i >= 0;i--)
    {   
        int A = a[i][0],B = a[i][1],P = a[i][2];
        for (int x = 0;x <= mx;x++)
        {
            if (P >= x) dp[i][x] = dp[i + 1][x + A];
            else dp[i][x] = dp[i + 1][max(0,x - B)];
        }
    }
    vll pre(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + a[i][1];
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (x <= mx) 
        {
            cout << dp[0][x] << endl;
            continue ;
        }

        auto i = ranges::lower_bound(pre,x - mx) - pre.begin();
        if (i == n + 1) cout << x - pre[n] << endl;
        else cout << dp[i][max(0LL,x - pre[i])] << endl;
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