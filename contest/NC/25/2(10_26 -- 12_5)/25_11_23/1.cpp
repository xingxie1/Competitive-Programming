#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int x,y,p1,p2;
    cin >> x >> y >> p1 >> p2;
    if (x > y) cout << "A";
    else if (x < y) cout << "B";
    else if (x == y)
    {
        if (p1 == p2) cout << "C";
        else if (p1 < p2) cout << "A";
        else cout << "B";
    }
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