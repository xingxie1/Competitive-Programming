#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int MOD = (int)1e9 + 7;
void solve()
{
    int n1;
    cin >> n1;
    string s;
    cin >> s;
    vt a;
    for (int i = 0;i < n1;i++)
    {
        if (s[i] == '1') a.push_back(i);
    }
    if (a.size() <= 1) cout << 0 << endl;
    else 
    {
        long long ans = 0,n = a.size();
        for (int i = 0;i < n;i++)
        {
            ans += 1LL * i * a[i];
            ans %= MOD;
            ans -= 1LL * (n - i - 1) * a[i];
            ans %= MOD;
        }
        cout << ans;
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