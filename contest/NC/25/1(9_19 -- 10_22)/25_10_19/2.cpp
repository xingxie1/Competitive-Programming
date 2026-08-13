#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n,ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0;i < n;i++)
    {
        vt cnt(4);
        for (int j = i;j < n;j++)
        {
            cnt[s[j] - '0']++;
            if (cnt[1] == cnt[2] && cnt[2] == cnt[3])
            {
                ans ++;
            }
        }
    }
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