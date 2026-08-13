#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    ll a,b,c,m;
    cin >> a >> b >> c >> m;
    ll ab = lcm(a,b),ac = lcm(a,c),bc = lcm(b,c);
    ll abc = lcm(ab,c);
    ll x = 0,y = 0,z = 0;
    x = y = z = m / abc * 2;
    x += (m / ab + m / ac - m / abc * 2) * 3;
    y += (m / ab + m / bc - m / abc * 2) * 3;
    z += (m / ac + m / bc - m / abc * 2) * 3;
    x += (m / a - m / ab - m / ac + m / abc) * 6;
    y += (m / b - m / ab - m / bc + m / abc) * 6;
    z += (m / c - m / ac - m / bc + m / abc) * 6;
    cout << x << " " << y << " " << z << endl;
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