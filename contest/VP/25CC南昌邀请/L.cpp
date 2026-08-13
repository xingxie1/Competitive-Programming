#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
    cin >> a >> b;
    if (a == 30) cout << "Alice" << endl;
    else if (b == 30) cout << "Bob" << endl;
    else if (a >= 21 && a - b >= 2) cout << "Alice" << endl;
    else if (b >= 21 && b - a >= 2) cout << "Bob" << endl;
    else cout << "Underway" << endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

    return 0;
}