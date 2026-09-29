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

const int MX = 51;
ll F[MX]; // F[i] = i!

auto init = [] 
{
    F[0] = 1;
    for (int i = 1; i < MX; i++) 
    {
        F[i] = F[i - 1] * i;
    }
    return 0;
}();

// 从 n 个数中选 m 个数的方案数
ll comb(int n, int m) 
{
    ll r1 = 1,r2 = 1;
    for (int i = 0;i < m;i++) 
    {
        r1 *= (n - i);
        r2 *= (i + 1);
        ll g = gcd(r1,r2);
        r1 /= g;
        r2 /= g;
    }
    return r1 / r2;
}


void solve()
{
    int n,a,b;
    cin >> n >> a >> b;
    vll v(n);
    for (int i = 0;i < n;i++) cin >> v[i];
    ll sum = 0;
    ranges::sort(v,{},[&](auto& x){
        return -x;
    });
    ll last = v[a];
    int cc = 0,cnt = 0;
    for (ll x : v) cnt += x == last;
    for (int i = 0;i < a;i++)
    {   
        sum += v[i];
        cc += v[i] == last;
    }
    cout << 1.0 * sum / a << endl;
    ll ans = comb(cnt,cc);
    if (last == v[0]) 
    {
        ans = 0;
        for (int i = a;i <= b;i++) ans += comb(cnt,i);
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