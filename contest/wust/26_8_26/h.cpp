#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    double ans = (long double)3 * n / 2;
    // cout << ans << endl;
    printf("%.4lf\n",ans);
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int _ = 1;
    cin >> _;
    // cout << setprecision(4);
    while (_--) solve();

}