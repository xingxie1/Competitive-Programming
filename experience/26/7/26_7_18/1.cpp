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
    ll N,M,A,B;
    cin >> N >> M >> A >> B;
    ll ans = 0;
    for (int i = 0;i <= min(N / 2,M);i++)
    {
        ll x = min((N - 2 * i),(M - i) / 2) * B;
        ans = max(ans,1LL * i * A + x);
    }
    cout << ans << endl;
    // auto f = [&](ll n,ll m,ll a,ll b) 
    // {
    //     ll mn = min(n / 2,m);
    //     ll ans = mn * a;
    //     n -= 2 * mn;
    //     m -= mn;
    //     mn = min(m / 2,n);
    //     ans += mn * b;
    //     return ans;
    // };  
    // ll ans = max(f(N,M,A,B),f(M,N,B,A));
    // cout << ans << endl;
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