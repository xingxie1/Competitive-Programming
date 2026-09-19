#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
using vt = vector<int>;
using vll = vector<ll>;

void solve()
{
    ll n;
    cin >> n;
    if (n % 2 == 0) cout << 1 << " " << n / 2 << " " << -1 << endl;
    else cout << -1 << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

    return 0;
}