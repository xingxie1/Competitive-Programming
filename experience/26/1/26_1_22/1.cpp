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
    vt a(4);
    for (int i = 0;i < 4;i++) cin >> a[i];
    if (a[0] == 0) cout << 1 << endl;
    else cout << a[0] + min(a[1],a[2]) * 2 + min(a[0] + 1,abs(a[2] - a[1]) + a[3]) << endl;
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