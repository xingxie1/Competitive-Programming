#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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
    ll n,c,d;
    cin >> n >> c >> d;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    while (a.size() < d) a.push_back(0);
    n = a.size();
    ranges::sort(a,{},[&](auto& x) {return -x;});
    ll sum = 0,mx = 0;
    for (int i = 0;i < n;i++) 
    {
        if (i < d) sum += a[i];
        mx = max(mx,1LL * a[i]);
    }
    if (1LL * d * mx < c) 
    {
        cout << "Impossible" << endl;
        return ;
    }
    if (sum >= c) 
    {
        cout << "Infinity" << endl;
        return ;
    }
    int l = -1,r = d;
    auto check = [&](int k)
    {
        ll sum = 0;
        for (int i = 0;i <= k;i++) sum += a[i];
        sum *= (d / (k + 1));
        int res = d % (k + 1);
        for (int i = 0;i < res;i++) sum += a[i];
        return sum >= c;
    };
    while (l + 1 < r) 
    {
        int m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << endl;
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