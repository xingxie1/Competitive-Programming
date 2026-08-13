#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int mod = (int)1e9+7;
void solve()
{
    int n;
    cin >> n;
    long long x,y;
    cin >> x >> y;
    for (int i = 1;i < n;i++)
    {
        long long a,b;
        cin >> a >> b;
        long long nx = 1LL * (a*x - b*y) % mod;
        long long ny = 1LL * (a*y+b*x) % mod;
        x = nx;
        y = ny;
    }
    if (x < 0) x = mod + x;
    if (y < 0) y = mod + y;
    cout << x << " " << y;
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