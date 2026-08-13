#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1 = 0,cnt2 = 0;
    for (char c : s)
    {
        if (c == '1') cnt1++;
        if (c == '6') cnt2++;
    }
    cout << min (cnt1,cnt2);
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