#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;
#define PI 3.1415926535

void solve()
{
    int n,r;
    cin >> n >> r;
    int i1,i2;
    cin >> i1 >> i2;
    if (i1 > i2) swap(i1,i2);
    i2 = i2 - i1 + 1;
    i1 = 1;
    int mn = min(i2 - i1,n - i2 + 1);
    double a = 180.0 / n;
    a = a / 180.0 * PI;
    double ans = mn * 2 * r * sin(a);
    printf ("%.7lf",ans);
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