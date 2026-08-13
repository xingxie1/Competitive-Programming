#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    ll a,b,c;
    cin >> a >> b >> c;
    if (a == b) cout << "YES" << endl;
    else if (c == 0) cout << "NO" << endl;
    else if (1LL * (b - a) % c == 0 && 1LL * (b - a) * c > 0) cout << "YES" << endl;
    else cout << "NO" << endl;

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