#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n,x,y;
    cin >> n >> x >> y;
    
    if (x == y) cout << 0 << endl;
    else if ((x & (-x)) == (y & (-y)) || (popcount(1ull * x) == popcount(1ull * y))) cout << 1 << endl;
    else cout << 2 << endl;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //ds
    int _ = 1;
    cin >> _;
    while (_--) solve();

}