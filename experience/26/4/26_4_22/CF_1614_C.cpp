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
const int MOD = (int)1e9+7;

ll qpow (ll a,ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vvt a(m,vt(3));
    ll sum = 0;
    for (int i = 0;i < m;i++) 
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        sum |= a[i][2];
    }
    cout << qpow(2,n - 1) * sum % MOD << endl;
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