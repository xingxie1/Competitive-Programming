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
    string s;
    cin >> s;
    int k;
    cin >> k;
    vt a(26);
    for (int i = 0;i < 26;i++) cin >> a[i];
    int mxi = 0;
    for (int i = 0;i < 26;i++)
    {
        if (a[i] > a[mxi]) mxi = i;
    }
    int ans = 0;
    for (int i = 0;i < s.size();i++)
    {
        char c = s[i];
        ans += a[c - 'a'] * (i + 1); 
    }
    int j = s.size() + 1;
    while (k--)
    {
        ans += a[mxi] * (j++);
    }
    cout << ans << endl;
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