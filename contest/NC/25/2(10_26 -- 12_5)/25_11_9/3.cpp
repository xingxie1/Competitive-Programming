#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n,m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0;i < n;i++)
    {
        if (i + 1 <= n)
        {
            ans += (m - 1);
        }
        if (i + 2 <= n)
        {
            ans += m;
        }
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