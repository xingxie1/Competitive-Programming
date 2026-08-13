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
    int n, m, k;
    cin >> n >> m >> k;
    
    umap<int,int> cnt;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) 
        {
            int x;
            cin >> x;
            cnt[x]++;
        }
    }
    ll ans = 0,sum = 0;
    for (auto& [x , c] : cnt)
    {
        if (c >= 2)
        {
            if (x + 1 >= k) ans += c / 2;
            cnt[x + 1] += c / 2;
            sum += c / 2;
        }
    }
    cout << sum << " " << ans << endl;

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