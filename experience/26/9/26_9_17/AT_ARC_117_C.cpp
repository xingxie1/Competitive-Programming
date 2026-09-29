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

// Lucas 定理
// 求 C(n, k) % p
// 要求：p 是质数，并且 p 不能太大（需要 O(p) 预处理）

ll P;
vector<ll> F, INV_F;

// 快速幂
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

// 初始化阶乘和逆阶乘
// Lucas 中只需要计算 C(a,b)，其中 0 <= a,b < P
// 所以预处理到 P - 1 即可
void init_lucas(ll p)
{
    P = p;

    F.resize(P);
    INV_F.resize(P);

    F[0] = 1;
    for (ll i = 1; i < P; i++) F[i] = F[i - 1] * i % P;

    INV_F[P - 1] = qpow(F[P - 1], P - 2);

    for (ll i = P - 1; i >= 1; i--) INV_F[i - 1] = INV_F[i] * i % P;
}

// C(n, k) % P
// 这里要求 n < P
ll C_lucas(ll n, ll k)
{
    if (k < 0 || k > n) return 0;
    return F[n] * INV_F[k] % P * INV_F[n - k] % P;
}

// Lucas 定理
ll lucas(ll n, ll k)
{
    if (k == 0) return 1;
    return C_lucas(n % P, k % P) * lucas(n / P, k / P) % P;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> p;
    p['B'] = 0;
    p['W'] = 1;
    p['R'] = 2;
    ll ans = 0;
    init_lucas(3);
    for (int i = 0;i < n;i++)
    {
        char c = s[i];
        ans += p[c] * lucas(n - 1,i);
        ans %= 3;
    }
    if ((n - 1) & 1) ans = (-ans + 3) % 3;
    if (ans == 0) cout << "B" << endl;
    else if (ans == 1) cout << "W" << endl;
    else cout << "R" << endl;
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