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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll pre(n + 1),suf(n + 1);
    int last = 0;
    for (int i = 1;i < n;i++)
    {
        int mn = min(a[i - 1] - last,a[i]);
        last = mn;
        pre[i + 1] = pre[i] + mn;
    }
    // for (int x : pre) cout << x << " ";
    last = 0;
    for (int i = n - 2;i >= 0;i--)
    {
        int mn = min(a[i],a[i + 1] - last);
        last = mn;
        suf[i] = suf[i + 1] + mn;
    }
    // for (int x : suf) cout << x << " ";
    ll ans = 0;
    for (int i = 0;i < n;i++)
    {
        ans = max(ans,pre[i] + suf[i + 1] + a[i]);
    }
    cout << ans << endl;
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