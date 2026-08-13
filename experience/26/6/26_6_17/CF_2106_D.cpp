#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n),b(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    vt pre(n + 1),suf(n + 1);
    int j = 0;
    for (int i = 0;i < n;i++) 
    {
        pre[i + 1] = pre[i];
        if (j < m && a[i] >= b[j])
        {
            pre[i + 1]++;
            j++;
        }
    }
    j = m - 1;
    for (int i = n - 1;i >= 0;i--) 
    {
        suf[i] = suf[i + 1];
        if (j >= 0 && a[i] >= b[j]) 
        {
            suf[i]++;
            j--;
        }
    }
    int ans = INT_MAX;
    if (pre[n - 1] == m || suf[0] == m) 
    {
        cout << 0 << endl;
        return ;
    }
    for (int i = 0;i <= n;i++) 
    {
        if (pre[i] + suf[i] == m - 1) 
        {
            ans = min(ans,b[pre[i]]);
        }
    }
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
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