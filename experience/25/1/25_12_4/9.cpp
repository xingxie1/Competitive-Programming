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
    int n;
    cin >> n;
    vector<string> ans(n);
    for (int i = 0;i < n;i++) cin >> ans[i];
    vt cnt(n);
    for (int i = 0;i < n;i++)
    {
        if (ans[i].size() != s.size()) continue;
        for (int j = 0;j < ans[i].size();j++)
        {
            if (ans[i][j] == s[j]) cnt[i]++;
        }
    }
    int mx = 0;
    vector<string> aaa;
    for (int i = 0;i < n;i++) 
    {
        if (cnt[i] > mx)
        {
            mx = cnt[i];
            aaa.clear();
            aaa.push_back(ans[i]);
        }
        else if (cnt[i] == mx) aaa.push_back(ans[i]);
    }
    for (int i = 0;i < aaa.size();i++) cout << aaa[i] << endl;
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