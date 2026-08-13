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
    int l,r,p,q;
    cin >> l >> r >> p >> q;
    auto calc = [&](int n)
    {
        int v = min((n + 1) % q,p);
        ll res = 1LL * (((n + 1) / q) * (p * (p - 1) / 2)) + 1LL * v * (v - 1) / 2;
        return res;
    };
    cout << calc(r) - calc(l - 1) << endl;
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