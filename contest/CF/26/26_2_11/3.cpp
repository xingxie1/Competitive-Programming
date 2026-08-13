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
    ll p,q;
    cin >> p >> q;
    auto check = [&]()
    {
        if (3 * p > 2 * q) return 1;
        else if (3 * p == 2 * q) return 0;
        else return -1;
    };
    if (check() == 0) cout << "Bob" << endl;
    else if (check() == 1)
    {
        ll t = 3 * p - 2 * q;
        if (q > t && p > t)
        {
            cout << "Bob" << endl;
        }
        else cout << "Alice" << endl;
    }
    else 
    {
        cout << "Alice" << endl;
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