#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
void solve()
{
    int n,m;
    string s;
    cin >> n >> m >> s;
    int t = stoi(s.substr(0,2)) * 60 + stoi(s.substr(3,2));
    // cout << t << endl;

    if (m >= 50 || m >= n / 5.0 || t >= 240) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

    return 0;
}