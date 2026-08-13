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
    int n,x;
    cin >> n >> x;
    ll ans = 0;
    for (int a = 1;a <= min(x - 2,(n - 1) / 2);a++)
    {
        ll cnt = 0;
        for (int b = 1;b <= min((n - a - 1) / a ,x - a);b++)
        {
            cnt += min((n - a * b) / (a + b),x - a - b);
        }
        ans += cnt;
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