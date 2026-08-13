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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

ll qpow(ll a,ll b)
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
    string a,b;
    cin >> n >> m >> a >> b;
    ranges::reverse(a);
    ranges::reverse(b);
    vt p;
    ll ans = 0;
    vt d(n + 1);
    for (int i = 0;i < m;i++) 
    {
        if (i < n && a[i] == '1') p.push_back(i);
        if (b[i] == '1') 
        {
            int j = p.size();
            d[j]++;
        }
    }
    if (p.empty()) 
    {
        cout << 0 << endl;
        return ;
    }
    ll c = 0;
    for (int i = p.size() - 1;i >= 0;i--)
    {
        c += d[i + 1];
        // cout << c << endl;
        ans = (ans + qpow(2,p[i]) * c % MOD) % MOD;
    }   
    cout << ans << endl;
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