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
    int n,k;
    cin >> n >> k;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi,a[i].se = i;
    ranges::sort(a,{},[&](auto& b){return pair{-b.fi,-b.se};});
    int ans = 0;
    for (int i = 0;i < k;i++) ans += a[i].fi;
    cout << ans << endl;
    vt b;
    for (int i = 0;i < k;i++) b.push_back(a[i].se + 1);
    // for (int x : b) cout << x << " ";
    b.push_back(0);
    ranges::sort(b);
    for (int i = 1;i < b.size();i++)
    {
        if (i == b.size() - 1) cout << n - b[i - 1] << " ";
        else cout << b[i] - b[i - 1] << " ";
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