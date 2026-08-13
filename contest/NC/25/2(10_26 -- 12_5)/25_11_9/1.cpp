#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int a,b;
    cin >> b >> a;
    if (a == 1 && b == 1) cout << "LU";
    else if (a == 1 && b == 2) cout << "RU";
    else if (a == 2 && b == 1) cout << "LD";
    else cout << "RD";
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