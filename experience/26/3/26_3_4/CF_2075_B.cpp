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
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll ans = 0;
    if (k == 1)
    {
        int mx1 = 0,mx2 = 0;
        for (int i = 0;i < n - 1;i++)
        {
            mx1 = max(mx1,a[i]);
        }
        for (int i = 1;i < n;i++)
        {
            mx2 = max(mx2,a[i]);
        }
        ans = max(a[0] + mx2,a[n - 1] + mx1);
        cout << ans << endl;
        return ;
    }
    ranges::sort(a);
    ans = accumulate(a.end() - k - 1,a.end(),0LL);
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