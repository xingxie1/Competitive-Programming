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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
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
    int n,k;
    cin >> n >> k;
    vt x(n),y(n);
    for (int i = 0;i < n;i++) cin >> x[i];
    for (int i = 0;i < n;i++) cin >> y[i];
    ranges::sort(x);
    vll pre(n + 1);
    int l = 0,r = 0;
    ll ans = 0;
    while (r < n) 
    {
        while (l < r && x[r] - x[l] > k) l++;
        ll cur = r - l + 1;
        ans = max(ans,cur + pre[l]);
        pre[r + 1] = max(pre[r],cur);
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