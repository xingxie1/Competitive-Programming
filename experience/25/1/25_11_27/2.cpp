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
    string s;
    cin >> s;
    unordered_map<int,int> cnt1,cnt2;
    long long ans = 0;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == 'R') ans += cnt2[a[i]];
        else ans += cnt1[a[i]];
        if (s[i] == 'R') cnt1[a[i]]++;
        else cnt2[a[i]]++;
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