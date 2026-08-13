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
    int l,r,d,u;
    cin >> l >> r >> d >> u;
    auto f = [&](int y)
    {
        ll sum = 0;
        for (int x = l;x <= r;x++)
        {
            if (abs(x) >= abs(y)) 
            {
                if (abs(x) % 2 == 0) sum += y + 1;
            }
            else 
            {
                if (abs(x) % 2 == 0)
                {
                    sum += abs(x);
                    sum += (y - abs(x)) / 2 + 1;
                }
                else 
                {
                    sum += (y - abs(x) + 1) / 2;
                }
            }
        }
        return sum;
    };

    ll ans = 0;
    if (1LL * u * d > 0)
    {
        if (d > 0) ans = f(u) - f(d - 1);
        else ans = f(abs(d)) - f(abs(u) - 1);
        // cout << f(u) << endl;
        // cout << f(d - 1) << endl;
    }
    else 
    {
        ans = f(abs(u)) + f(abs(d)) - f(0);
    }
    // cout << f(abs(u)) << endl;
    // cout << f(0) << endl;
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