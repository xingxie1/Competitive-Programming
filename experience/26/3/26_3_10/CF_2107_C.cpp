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
    ll n,k;
    cin >> n >> k;
    vll a(n);
    string s;
    cin >> s;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '0') a[i] = -1e13;
    }
    
    vll dp(n + 1);
    for(int i = 0;i < n;i++)
    {
        dp[i + 1] = max(dp[i],0LL) + a[i];
    }
    ll mx = ranges::max(dp);
    if (mx > k)
    {
        cout << "NO" << endl;
        return ;
    }
    else if (mx == k)
    {
        cout << "YES" << endl;
        for (ll x : a) cout << x << " ";
        cout << endl;
        return ;
    }
    int j = -1;
    for (int i = n - 1;i >= 0;i--)
    {
        if (s[i] == '0') 
        {
            j = i;
            a[i] = 0;
            break;
        }
    }
    if (j == -1) 
    {
        cout << "NO" << endl;
        return ;
    }
    ll sum = 0,mxsuf = 0;
    for (int i = j + 1;i < n;i++) 
    {
        sum += a[i];
        mxsuf = max(mxsuf,sum);
    }
    sum = 0;
    ll mxpre = 0;
    for (int i = j - 1;i >= 0;i--) 
    {
        if (s[i] == '0') break;
        sum += a[i];
        mxpre = max(mxpre,sum);
    }
    a[j] = k - mxpre - mxsuf;
    cout << "YES" << endl;
    for (ll x : a) cout << x << " ";
    cout << endl;
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