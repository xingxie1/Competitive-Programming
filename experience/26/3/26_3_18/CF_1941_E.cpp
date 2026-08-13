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
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k,d;
    cin >> n >> m >> k >> d;
    vvt a(n,vt(m));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) cin >> a[i][j];
    }
    vll f(n);
    for (int i = 0;i < n;i++)
    {
        vll dp(m,LLONG_MAX / 2);
        deque<int> q;
        dp[0] = 1;
        q.push_back(0);
        for (int j = 1;j < m;j++)
        {
            ll mn = dp[q.front()];
            dp[j] = mn + a[i][j] + 1;
            if (q.front() <= j - d - 1) q.pop_front();
            while (!q.empty() && dp[j] <= dp[q.back()]) q.pop_back();
            q.push_back(j);
        }
        f[i] = dp[m - 1];
    }
    ll ans = LLONG_MAX,sum = 0;
    int l = 0,r = 0;
    while (r < n)
    {
        sum += f[r];
        if (r - l + 1 == k)
        {
            ans = min(ans,sum);
            sum -= f[l];
            l++;
        }
        r++;
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