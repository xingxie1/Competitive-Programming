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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n == 1) 
    {
        cout << -1 << endl;
        return ;
    }
    ranges::sort(a);
    int j = (n - 1) / 2;
    int l = j,r = j;
    while (l >= 0 && a[l] == a[j]) l--;
    while (r < n && a[r] == a[j]) r++;
    if (l < 0 && r >= n) 
    {
        cout << -1 << endl;
        return ;
    }
    int ans = min(n - 2 * (l + 1),n - (2 * (n - r - 1) + 1));
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