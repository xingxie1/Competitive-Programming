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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    ll n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt d(n);
    d[0] = a[0];
    for (int i = 1;i < n;i++)
    {
        d[i] = a[i] - a[i - 1];
    }
    // for (int x : d) cout << x << " ";
    // cout << endl;
    int l = 0,r = 0,ans = 0;
    ll sum = 0;
    while (r < n)
    {
        sum += abs(d[r] - 1);
        while (l <= r && sum > k) 
        {
            sum -= abs(d[l] - 1);
            l++;
        }
        if (l == 0 && r == n - 1) ans = n;
        else ans = max(ans,r - l + 2);
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