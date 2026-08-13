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
    int n,q;
    cin >> n >> q;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll pre(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + a[i];
    while (q--)
    {
        int t;
        cin >> t;
        auto it = upper_bound(pre.begin(),pre.end(),t) - pre.begin();
        cout << it << endl;
    }
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