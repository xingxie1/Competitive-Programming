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
    ll n,x;
    cin >> n >> x;
    vt a(n),b(n),c(n);
    for (int i = 0;i < n;i++) cin >> a[i] >> b[i] >> c[i];
    vll d(n);
    ll cnt = 0,sum = 0;
    int mxi = 0;
    for (int i = 0;i < n;i++)
    {
        sum += 1LL * a[i] * (b[i] - 1);
        d[i] = 1LL * a[i] * b[i] - c[i];
        if (d[i] > d[mxi]) mxi = i;
    }
    if (sum >= x) 
    {
        cout << 0 << endl;
        return ;
    }
    x -= sum;
    if (d[mxi] <= 0)
    {
        cout << -1 << endl;
        return ;
    }
    cnt = 1LL * (x + d[mxi] - 1) / d[mxi];
    cout << cnt << endl;
    // cout << d[mxi] << endl;
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