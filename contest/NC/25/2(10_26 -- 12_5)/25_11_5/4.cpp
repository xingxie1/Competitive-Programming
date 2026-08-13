#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    unordered_map<int,long long> cnt;
    long long ans = 0;
    for (int i = 0;i < n;i++) cin >> a[i];
    cnt[0] = 1;
    int s = 0;
    for (int x : a)
    {
        s ^= x;
        ans += cnt[s];
        cnt[s]++;
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