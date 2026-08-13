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
    ll l,r;
    cin >> l >> r;
    ll ans = 0;
    auto f = [&](ll x) 
    {
        if (x == -1) return 0LL;
        if (x == 0 || x == 1) return 0LL;
        if (x == 2) return 1LL;
        if (x == 3) return 2LL; 
        int m = bit_width(1ull * x);
        ll ans = 1LL * (m - 1) * (m - 2) / 2;
        ans += m - 1;
        for (int i = m - 2;i >= 0;i--) 
        {
            if (x >> i & 1) 
            {
                ans += i + 1;
                return ans;
            }
        }
        return ans;
    };
    cout << f(r) - f(l - 1) << endl;
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