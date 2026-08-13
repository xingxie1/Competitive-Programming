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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n == 1)
    {
        cout << 0 << endl;
        return ;
    }
    else if (n == 2)
    {
        cout << 1 << endl;
        return ;
    }
    else if (n == 3)
    {
        cout << 2 << endl;
        return ;
    }

    int mn1 = min(a[1] - a[0],a[2] - a[1]);
    int mn2 = INT_MAX;
    int ans = 1;
    for (int i = 1;i < n - 2;i++)
    {
        mn2 = min(a[i + 1] - a[i],a[i + 2] - a[i + 1]);
        if (mn1 + mn2 > a[i + 1] - a[i]) ans++;
        mn1 = mn2;
    }
    ans++;
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