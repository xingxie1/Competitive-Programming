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
    ll n, k, x;
    cin >> n >> k >> x;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll sum = 0;
    for (int i = 0;i < k;i++) sum += a[i];
    if (sum < x) 
    {
        cout << -1 << endl;
        return ;
    }
    sum = 0;
    int cnt = n - k;
    for (int i = k - 1;i >= 0;i--)
    {
        sum += a[i];
        cnt++;
        if (sum >= x) break;
    }
    int ans = cnt;
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