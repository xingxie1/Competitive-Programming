#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    long long ans = LLONG_MAX;
    for (int i = 0;i < n;i++)
    {
        unordered_map<int,int> cnt;
        long long x = LLONG_MAX;
        if (a[i] == 1) x = 2;
        for (int j = 2;j < a[i];j++)
        {
            if (gcd(j,a[i]) == 1)
            {
                x = j;
                break;
            }
        }
        ans = min(ans,x);
    }
    if (ans == LLONG_MAX) cout << -1 << endl;
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