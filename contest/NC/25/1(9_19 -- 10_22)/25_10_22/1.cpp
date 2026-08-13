#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int a,b,c,x,y,z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;

    cout << min(a,y) + min(b,z) + min(c,x);
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