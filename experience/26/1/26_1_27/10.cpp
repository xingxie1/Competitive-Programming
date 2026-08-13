#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vt cnt(26);
    for (char c : s)
    {
        cnt[c - 'a']++;
    }
    string ans(n,' ');
    int last = 0;
    while (1)
    {
        int mxi = 0;
        for (int j = 0;j < 26;j++)
        {
            if (cnt[j] > cnt[mxi]) mxi = j;
        }
        if (cnt[mxi] == 0) break;
        for (int i = last;i < n;i += 2)
        {
            ans[i] = ('a' + mxi);
            cnt[mxi]--;
            last = i + 2;
            if (last >= n) last = 1;
            if (!cnt[mxi]) break;
            if (i + 2 >= n) i = -1;
        }
    }
    cout << ans << endl;
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