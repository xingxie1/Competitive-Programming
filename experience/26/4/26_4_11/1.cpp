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
    ll n,s;
    cin >> n >> s;
    vvll a(n,vll(3));
    for (int i = 0;i < n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    double l = -1,r = LLONG_MAX / 2.0;
    auto check = [&](double R)
    {
        ll sum = 0;
        for (int i = 0;i < n;i++)
        {
            ll x = a[i][0],y = a[i][1],v = a[i][2];
            if (x * x + y * y <= R * R) sum += v;
        }
        return sum >= s;
    };
    int cnt = 100;
    while (cnt--)
    {
        double m = l + (r - l) / 2.0;
        if (check(m)) r = m;
        else l = m;
    }
    cout << fixed << setprecision(10);
    if (r == LLONG_MAX / 2.0) cout << -1 << endl;
    else cout << r << endl;
    // cout << LLONG_MAX / 2;
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