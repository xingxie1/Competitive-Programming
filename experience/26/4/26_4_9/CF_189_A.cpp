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
    vt a(3);
    cin >> n >> a[0] >> a[1] >> a[2];
    ranges::sort(a);
    int ans = 0;
    for (int i = 0;;i++)
    {
        if (i * a[0] > n) break;
        int res = n - a[0] * i;
        for (int j = 0;;j++)
        {
            if (i * a[0] + j * a[1] > n) break;
            if ((res - a[1] * j) % a[2] == 0) ans = max(ans,i + j + (res - a[1] * j) / a[2]);
        }
    }
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