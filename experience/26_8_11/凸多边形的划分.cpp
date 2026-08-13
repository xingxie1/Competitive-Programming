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

void print_i128(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    if (x < 0) {
        cout << '-';
        x = -x;
    }

    string s;

    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }

    reverse(s.begin(), s.end());
    cout << s;
}

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector dp(n,vector<i128>(n,(i128)LLONG_MAX * INT_MAX));
    for (int i = n - 2;i >= 0;i--)
    {
        for (int j = i + 1;j < n;j++)
        {
            dp[i][i + 1] = 0;
            for (int k = i + 1;k < j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j] + (i128)a[i] * a[j] * a[k]);
            }
        }
    }
    print_i128(dp[0][n - 1]);
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