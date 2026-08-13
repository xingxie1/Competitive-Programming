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
    int l = 0,r = 0,ans = 0;
    vt cnt(2);
    while (r < n)
    {
        cnt[s[r] - '0']++;
        while (cnt[0] > k && cnt[1] > k)
        {
            cnt[s[l] - '0']--;
            l++;
        }
        ans = max(ans,r - l + 1);   
        r++;
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