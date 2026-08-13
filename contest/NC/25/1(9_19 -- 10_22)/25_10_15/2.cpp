#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n,x,a,b;
    cin >> n >> x >> a >> b;
    double sum = 0;
    sum = n * x * a / 100.0 + n*(100-x) * b / 100.0;
    printf ("%.2lf",sum);
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