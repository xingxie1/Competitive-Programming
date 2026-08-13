// https://codeforces.com/problemset/problem/1827/A
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
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    ll ans = 1;
    for (int i = 0;i < n;i++)
    {
        int cnt = n - (upper_bound(a.begin(),a.end(),b[i]) - a.begin());
        ans = ans * max(cnt - i,0) % MOD;
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