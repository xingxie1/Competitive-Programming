#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    if (b - a == 1 && c - b == 1) cout << "Yes"<<endl;
    else cout <<"No" << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}