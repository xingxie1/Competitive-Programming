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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

ll qpow(ll a,ll b)
{
    a %= MOD;
    ll res = 1;
    while (b) 
    {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
};
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    ll sum = qpow(10,n - 1);
    vt pow10(n);
    pow10[0] = sum;
    for (int i = 1;i < n;i++) 
    {
        pow10[i] = qpow(10,n - i - 1) * qpow(2,i - 1) % MOD;
        sum = (sum + pow10[i]) % MOD;
    }
    for (int i = 0;i < n;i++)
    {
        ll x = s[i] - '0';
        // cout << sum << endl;
        ans = (ans + x * sum % MOD) % MOD;
        sum = (sum - pow10[i] + MOD) % MOD;
        if (i + 1 < n) 
        {
            sum = (sum + pow10[i + 1]) % MOD;
            pow10[i + 1] = pow10[i + 1] * 2 % MOD;
        }
    }
    cout << ans << endl;
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