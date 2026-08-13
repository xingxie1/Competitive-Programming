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
    ll n,m;
    cin >> n >> m;
    auto query = [&](int l,int r)
    {
        cout << "? " << l << " " << r << endl;
        ll d;
        cin >> d;
        return d;
    };
    ll d1 = query(1,1);
    ll d2 = query(n,m);
    ll d3 = query(1,m);
    ll x1 = (n + 1 + d3 - d2) / 2;
    ll y1 = (n + 2 * m - 1 - d2 - d3) / 2;
    ll x2 = (d1 + d3 + 3 - m) / 2;
    ll y2 = (d1 - d3 + m + 1) / 2;
    if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m)
    {
        ll d4 = query(x1,y1);
        if (d4 == 0) 
        {
            cout << "! " << x1 << " " << y1 << endl;
        }
        else 
        {
            cout << "! " << x2 << " " << y2 << endl;
        }
    }
    else cout << "! " << x2 << " " << y2 << endl;

    
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