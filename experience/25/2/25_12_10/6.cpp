// https://codeforces.com/problemset/problem/1176/B
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
    vt a(n);
    int cnt0 = 0,cnt1 = 0,cnt2 = 0;
    for (int i = 0;i < n;i++ ) 
    {
        cin >> a[i];
        if (a[i] % 3 == 0) cnt0++;
        else if (a[i] % 3 == 1) cnt1++;
        else cnt2++;
    }
    int ans = cnt0;
    ans += min(cnt1,cnt2) + abs(cnt1 - cnt2) / 3;
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