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
    int n,m,l;
    cin >> n >> m >> l;
    vt a(n);
    vll pre(n + 1);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    ll s = 0;
    int flag = 1;
    if (l > pre[1]) flag = 0;
    for (int i = 0;i < m;i++)
    {
        int y;
        cin >> y;
        s += y;
        auto j = ranges::upper_bound(pre,s) - pre.begin();
        if (j != n + 1 && s + l > pre[j])flag = 0;
    }
    if (!flag) cout << "YES" << endl;
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