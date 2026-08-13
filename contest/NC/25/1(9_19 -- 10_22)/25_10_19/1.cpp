#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    if (a == 1) cout << 1 << " ";
    else if (b == 1) cout << 2 << " ";
    else if (c == 1) cout << 3 <<" ";
    if (a == 2) cout << 1 << " ";
    else if (b == 2) cout << 2 << " ";
    else if (c == 2) cout << 3 << " ";
    if (a == 3) cout << 1 << " ";
    else if (b == 3) cout << 2 << " ";
    else cout << 3 << " ";
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