#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vt cnt(26);
    int l = 0,r = 0,ans = INT_MAX;
    while (r < n)
    {
        cnt[s[r] - 'a']++;
        if (cnt[s[r] -  'a'] == k)
        {
            while (cnt[s[r] - 'a'] >= k)
            {
                cnt[s[l] - 'a']--;
                l++;
            }
            ans = min(ans,r - l + 2);
        }
        r++;
    }
    if (ans != INT_MAX)
        cout << ans;
    else cout << -1;
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