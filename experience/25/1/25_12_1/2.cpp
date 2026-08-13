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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    unordered_map<int,int> cnt;
    for (int x : a)
    {
        cnt[x]++;
    }
    int ans = 0,l = 0,ans_l = 0;
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        if (cnt[x] == 1)
        {
            int j = i;
            while (j < n && cnt[a[j]] == 1) j++;
            j--;
            if (j - i + 1 > ans)
            {
                ans = j - i + 1;
                ans_l = i;
            }
            i = j;
        }
    }
    if (ans == 0) cout << 0 << endl;
    else cout << ans_l + 1 << " " << ans_l + ans << endl;
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