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
    ll hc,dc,h2,d2;
    cin >> hc >> dc >> h2 >> d2;
    ll k,w,a;
    cin >> k >> w >> a;
    int flag = 0;
    for (int i = 0;i <= k;i++)
    {
        ll d1 = dc + i * w;
        ll h1 = hc + (k - i) * a;
        ll t1 = (h2 + d1 - 1) / d1;
        ll t2 = (h1 + d2 - 1) / d2;
        if (t1 <= t2) flag = 1;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

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