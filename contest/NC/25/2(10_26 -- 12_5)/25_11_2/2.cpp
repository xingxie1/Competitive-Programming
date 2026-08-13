#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if ((c < a && b < d) || (a < c && d < b)) cout << "A" << endl;
    else if (b < c || a > d) cout <<"B" << endl;
    else cout << "C" << endl;
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