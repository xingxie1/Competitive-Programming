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
    int n,m;
    cin >> n;
    m = 1 << n;
    vt a(m),p,q;
    for (int i = 0;i < m;i++) cin >> a[i];
    ll ans = 0;
    for (int j = 0;j < n;j++)
    {
        p.clear();
        q.clear();
        for (int i = 0;i < m;i++)
        {
            if (i >> j & 1) p.push_back(i);
            if (a[i] >> j & 1) q.push_back(i);
        }
        for (int i = 0;i < p.size();i++) ans += abs(p[i] - q[i]);
    }
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