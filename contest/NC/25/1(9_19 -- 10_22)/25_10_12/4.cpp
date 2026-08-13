#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int mod = (int)1e9+7;
long long f(int n)
{
    long long ans = 1;
    for (int i = 1;i <= n;i++)
    {
        ans *= i;
        ans %= mod;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    long long ans = 0;
    long long x = f(n-1);
    for (int i = 1;i <= n;i++)
    {
        ans += 1LL * ((i % 5) * x) % mod;
        ans %= mod;
    }
    cout << ans;
    
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