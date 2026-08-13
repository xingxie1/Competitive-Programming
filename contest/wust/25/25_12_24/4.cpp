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
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    map<int,vector<int>> cnt;
    for (int i = n - 1;i >= 0;i--)
    {
        int x = a[i];
        int c = 0;
        while (1)
        {
            cnt[x].push_back(c);
            if (x == 0) break;
            c++;
            x >>= 1;
        }
    }
    int ans = INT_MAX;
    for (auto &[x,b] : cnt)
    {
        if (cnt[x].size() < k) continue;
        sort(b.begin(),b.end());
        int s = 0;
        for( int i = 0;i < k;i++) s += b[i];
        ans = min(ans,s);
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