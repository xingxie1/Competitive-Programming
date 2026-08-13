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
    int n,m,d;
    cin >> n >> m >> d;
    vt a(m + 2);
    a[0] = 1 - d;
    for (int i = 1;i <= m;i++) cin >> a[i];
    a[m + 1] = n + 1;
    ll ans = m;
    auto f = [&](int l,int r ) 
    {
        return (r - l - 1) / d;
    };
    for (int i = 0;i <= m;i++) 
    {
        int L = a[i],R = a[i + 1];
        ans += f(L,R);
    }
    ll mn = LLONG_MAX,cnt = 0;
    for (int i = 1;i <= m;i++) 
    {
        ll old = 1 + f(a[i - 1],a[i]) + f(a[i],a[i + 1]);
        ll nw = f(a[i - 1],a[i + 1]);
        if (ans - old + nw == mn) cnt++;
        else if (ans - old + nw < mn) 
        {
            mn = ans - old + nw;
            cnt = 1;
        }
    }
    cout << mn << " " << cnt << endl;
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