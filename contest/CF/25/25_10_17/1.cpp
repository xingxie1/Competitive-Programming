#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    int ans = 0;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++)
    {
        int sum = 0;
        for (int j = i;j < n;j++)
        {
            sum += a[j];
            int x = (sum)/(j - i + 1);
            ans = max(ans,x);
        }
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