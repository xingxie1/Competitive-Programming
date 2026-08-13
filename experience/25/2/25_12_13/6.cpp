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
    int n,q,k;
    cin >> n >> q >> k;
    vt a(n);
    vll pre(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    vt b(n + 1);
    vll s(n + 1);
    for (int i = 1;i <= n;i++)
    {
        auto it = lower_bound(pre.begin(),pre.end(),pre[i - 1] + k);
        int j = it - pre.begin();
        b[i] = j;
        s[i] = s[i - 1] + b[i];
    }

    while (q--)
    {
        int l,r;
        cin >> l >> r;
        
        int cp = upper_bound(b.begin() + l,b.begin() + r + 1,r) - b.begin() - 1;
        int cnt = cp - l + 1;
        ll ans = 1LL * (r + 1) * cnt - (s[cp] - s[l - 1]);
        cout << ans << endl;
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

