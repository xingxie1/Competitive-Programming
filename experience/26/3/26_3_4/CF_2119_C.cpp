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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    ll n,l,r,k;
    cin >> n >> l >> r >> k;
    if (n % 2) cout << l << endl;
    else if (n == 2)
    {
        cout << -1 << endl;
    }
    else 
    {
        if (bit_width((uint64_t) r) > bit_width((uint64_t) l))
        {
            if (k <= n - 2) cout << l << endl;
            else cout << (1LL << (bit_width((uint64_t) l))) << endl;
        }
        else cout << -1 << endl;
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