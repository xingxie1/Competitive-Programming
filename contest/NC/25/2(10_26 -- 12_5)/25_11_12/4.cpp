#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;
#define PI 3.1415926535

void solve()
{
    int n;
    cin >> n;
    if (n % 2) cout << "Bob" << endl;
    else if ((n & (n - 1)) == 0) cout << "Alice";
    else cout << "Bob";
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