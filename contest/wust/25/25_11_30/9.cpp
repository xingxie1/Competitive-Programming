#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    ll a = 0,c = 0,m = 0,ac = 0,cm = 0,acm = 0;
    vector<int> ans;
    for (char ch : s)
    {
        if (ch == 'a')
        {
            ac = (ac + c) % MOD;
            acm = (acm + cm) % MOD;
            a = (a + 1) % MOD;
        }
        else if (ch == 'A')
        {
            a = (a + 1) % MOD;
        }
        else if (ch == 'C')
        {
            ac = (ac + a) % MOD;
            c = (c + 1) % MOD;
        }
        else if (ch == 'c')
        {
            c = (c + 1) % MOD;
            cm = (cm + m) % MOD;
        }
        else if (ch == 'M')
        {
            acm = (acm + ac) % MOD;
            cm = (cm + c) % MOD;
            m = (m + 1) % MOD;
        }
        else if (ch == 'm')
        {
            m = (m + 1) % MOD;
        }

        ans.push_back(acm % MOD);
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
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