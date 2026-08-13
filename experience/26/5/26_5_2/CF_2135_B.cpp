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
// #define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n ;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    vt dd1(n),dd2(n);
    for (int i = 0;i < n;i++) 
    {
        dd1[i] = a[i].fi + a[i].se;
        dd2[i] = a[i].fi - a[i].se;
    }
    ranges::sort(dd1);
    ranges::sort(dd2);
    ll mx = dd1.back();
    ll mn = dd2[0];
    ll B = 1e9;
    ll d1,d2;
    cout << "? R " << B << endl;
    cin >> d1;
    cout << "? R " << B << endl;
    cin >> d1;
    cout << "? U " << B << endl;
    cin >> d1;
    cout << "? U " << B << endl;
    cin >> d1;
    cout << "? L " << B << endl;
    cin >> d2;
    cout << "? L " << B << endl;
    cin >> d2;
    cout << "? L " << B << endl;
    cin >> d2;
    cout << "? L " << B << endl;
    cin >> d2;
    int x = (d1 - d2 + mx + mn) / 2;
    int y = (d1 + d2 - 8 * B + mx - mn) / 2;
    cout << "! " << x << " " << y << endl;
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