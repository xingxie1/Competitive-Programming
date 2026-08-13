#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;


void solve()
{
    int l,r;
    cin >> l >> r;
    if (l == 1 && r >= 9) cout << 2 << endl;
    else if (l == 1 && r < 9) cout << 1 << endl;
    else if (l > 1 && l <= 9 && r >= 9) cout << 1 << endl;
    else cout << 0 << endl;
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
    