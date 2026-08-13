#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int x,y,z;
    cin >> x >> y >> z;
    if (x >= y * z && (x - z * y) % (z - 1) == 0) cout << "Yes" ;
    else cout << "No";
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