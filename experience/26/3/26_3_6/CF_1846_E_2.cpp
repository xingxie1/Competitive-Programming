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

set<ll> st;
auto INIT = []
{
    for (ll q = 2;q <= 1000000;q++)
    {
        ll s = 1 + q + q * q;
        ll p = q * q;
        st.insert(s);
        while (1)
        {
            if (1e18 / q < p) break;
            p *= q;
            s += p;
            st.insert(s);  
        }
    }
    return 0;
}();

void solve()
{
    ll n;
    cin >> n;
    
    if (st.contains(n)) cout << "YES" << endl;
    else 
    {
        ll d = 4 * n - 3;
        if (d < 0) 
        {
            cout << "NO" << endl;
            return ;
        }
        ll r = (-1 + sqrt(4 * n - 3)) / 2;
        if (r >= 2 && r * r + r + 1 == n) cout << "YES" << endl;
        else cout << "NO" << endl;
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