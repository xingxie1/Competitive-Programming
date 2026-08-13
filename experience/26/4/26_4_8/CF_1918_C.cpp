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
    ll a,b,r;
    cin >> a >> b >> r;
    if (a == b) 
    {
        cout << 0 << endl;
        return ;
    }
    if (a < b) swap(a,b);
    int k = bit_width(1ull * (a ^ b)) - 1;
    ll x = 0;
    for (int i = k - 1;i >= 0;i--)
    {
        int ba = (a >> i) & 1;
        int bb = (b >> i) & 1;
        ll v = 1LL << i;
        if (ba && !bb)
        {
            if (x + v <= r) 
            {
                x += v;
                a ^= v;
                b ^= v;
            }
        }
    }
    cout << a - b << endl;
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