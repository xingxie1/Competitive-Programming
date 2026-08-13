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
    ll a,b,x,y,n;
    cin >> a >> b >> x >> y >> n;
    auto f = [&](ll a,ll b,ll x,ll y,ll n)
    {
        ll ans = 0;
        if (a - x >= n) 
        {
            a -= n;
            n = 0;
        }
        else 
        {
            n -= (a - x);
            a = x;
        }
        if (b - y >= n) 
        {
            b -= n;
            n = 0;
        }
        else 
        {
            n -= (b - y);
            b = y;
        }
        return 1LL * a * b;
    };
    cout << min(f(a,b,x,y,n),f(b,a,y,x,n)) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}