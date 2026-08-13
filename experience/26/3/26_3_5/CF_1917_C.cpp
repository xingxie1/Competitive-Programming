#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,k,d;
    cin >> n >> k >> d;
    vt a(n),b(k);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < k;i++) cin >> b[i];
    ll ans = 0;
    for (int i = 0;i < min(2 * n,d);i++)
    {
        int cnt = 0;
        for (int j = 0;j < n;j++)
        {
            if (a[j] == j + 1) cnt++;
        }
        ans = max(ans,1LL * cnt + (d - i - 1) / 2);
        for (int j = 0;j < b[i % k];j++) a[j]++;
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