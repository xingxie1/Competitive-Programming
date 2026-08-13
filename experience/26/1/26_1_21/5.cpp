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

ll sum(int l,int r)
{
    if (l > r) return 0;
    return 1LL * (l + r) * (r - l + 1) / 2;
}
void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    ll l = lcm(1LL * x,1LL * y);
    int p = n / x - n / l;
    int m = n / y - n / l;
    ll ans = sum(n - p + 1,n);
    ans -= sum(1,m);
    
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