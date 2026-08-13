#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    string s;
    int mod;
    while (cin >> s >> mod)
    {
        int res;
        for (int i = 0;i < s.size();i++)
        {
            res = res * 26 + s[i] - 'a';
        }
        if (res < mod) cout << -1 << endl;
        else 
        {
            int sum = 0,dd = res + mod;
            vector dp(7,vector<int>(dd + 1,0));
            for (int i = 5;i >= 0;i--)
            {
                for (int j = 0;j < 26;j++)
                {
                    if ()
                    dp[i + 1][]
                }
            }
        }
        
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