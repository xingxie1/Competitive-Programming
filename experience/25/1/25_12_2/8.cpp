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
    string s,t;
    cin >> s >> t;
    vector<string> ans;
    if (s[0] < t[0])
    {
        if (s[1] > t[1])
        {
            int mn = min(t[0] - s[0],s[1] - t[1]);
            int n = 0,m = 0;
            if (mn != s[1] - t[1])  n = s[1] - t[1] - mn;
            if (mn != t[0] - s[0]) m = t[0] - s[0] - mn;
            while (mn--) ans.push_back("RD");
            while (n--) ans.push_back("D");
            while (m--) ans.push_back("R");
        }
        else 
        {
            int mn = min(t[0] - s[0],t[1] - s[1]);
            int n = 0,m = 0;
            if (mn != t[1] - s[1]) n = t[1] - s[1] - mn;
            if (mn != s[0] - t[0]) m = s[0] - t[0] - mn;
            while (mn--) ans.push_back("RU");
            while (n--) ans.push_back("U");
            while (m--) ans.push_back("R");
        }
    }
    else 
    {
        if (s[1] > t[1])
        {
            int mn = min(t[0] - s[0],s[1] - t[1]);
            int n = 0,m = 0;
            if (mn != s[1] - t[1])  n = s[1] - t[1] - mn;
            if (mn != t[0] - s[0]) m = t[0] - s[0] - mn;
            while (mn--) ans.push_back("LD");
            while (n--) ans.push_back("D");
            while (m--) ans.push_back("L");
        }
        else 
        {
            int mn = min(t[0] - s[0],t[1] - s[1]);
            int n = 0,m = 0;
            if (mn != t[1] - s[1]) n = t[1] - s[1] - mn;
            if (mn != s[0] - t[0]) m = s[0] - t[0] - mn;
            while (mn--) ans.push_back("LU");
            while (n--) ans.push_back("U");
            while (m--) ans.push_back("L");
        }
    }
    cout << ans.size() << endl;
    for (int i = 0;i < ans.size();i++) cout << ans[i] << endl;
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