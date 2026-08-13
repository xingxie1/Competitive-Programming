#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt L(n + 1); 
    int l = 0,r = 0,cur = 0;
    while(r < n)
    {
        while ((cur & a[r]) != 0)
        {
            cur ^= a[l++];
        }
        cur |= a[r];
        L[r] = l;
        r++;
    }
    vll pre(n + 1),dp(n + 1);
    dp[0] = pre[0] = 1;
    for (int i = 0;i < n;i++)
    {
        int l = L[i];
        ll res = pre[i];
        if (l >= 1) res = (res - pre[l - 1] + mod) % mod;
        dp[i + 1] = res;
        pre[i + 1] = (pre[i] + dp[i + 1]) % mod;
    }
    cout << dp[n] << endl;
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