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
    int n,h,k;
    cin >> n >> h >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll sum = 0;
    for (int x : a) sum += x;
    ll m = h / sum;
    ll res = h % sum;
    ll ans = m * n;
    if (m > 0)
    {
        if (res == 0) 
        {
            ans += 1LL * (m - 1) * k;
            cout << ans << endl;
            return ;
        }
        else ans += 1LL * m * k;
    }
    vll pre(n + 1);
    for (int i = 0;i < n;i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }
    auto j = ranges::lower_bound(pre,res) - pre.begin();
    int mn = j,mx = 0;
    for (int i = n - 1;i >= j - 1;i--) mx = max(mx,a[i]);
    for (int i = 0;i < j;i++)
    {
        if (a[i] > mx) continue;
        auto k = ranges::lower_bound(pre,res - mx + a[i]) - pre.begin();
        mn = min(mn,max((int)k,i + 1));
    }
    cout << ans + mn << endl;

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