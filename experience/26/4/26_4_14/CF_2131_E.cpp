#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    if (a[n - 1] != b[n - 1])
    {
        cout << "NO" << endl;
        return ;
    }
    vt dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2;i >= 0;i--)
    {
        if (a[i] == b[i])
        {
            dp[i] = 1;
            continue;
        }
        if (dp[i + 1]) 
        {
            if ((a[i] ^ a[i + 1]) == b[i] || (a[i] ^ b[i + 1]) == b[i]) 
            {
                dp[i] = 1;
            }
        }
    }
    for (int x : dp)
    {
        if (!x)
        {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
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