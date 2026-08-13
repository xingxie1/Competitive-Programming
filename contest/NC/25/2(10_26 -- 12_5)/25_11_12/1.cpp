#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;


void solve()
{
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
   int ans = 0;
   for (int i = 0;i < min(m,n);i++)
   {
        if (s[i] != t[i]) ans++;
   }
    ans += abs(m - n);
    cout << ans;
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