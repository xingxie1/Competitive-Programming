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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    ll n,q;
    cin >> n >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        if (bit_width((uint64_t) x) == bit_width((uint64_t) n)) 
        {
            int b = bit_width((uint64_t) n);
            ll m = 1LL << b;
            ll ans = m / 2 - (m - 1 - n);
            cout << ans << endl;
        }
        else cout << (1LL << (bit_width((uint64_t) x) - 1)) << endl;
    }
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