#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
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
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = INT_MAX;
    vt b = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
    for (ll x : a)
    {
        for (int y : b)
        {
            if (x % y != 0)
            {
                ans = min(ans,y);
                break;
            }
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