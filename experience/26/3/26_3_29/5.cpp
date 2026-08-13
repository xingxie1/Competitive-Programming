#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt b;
    vt vis(n + 1);
    for (int x : a)
    {
        if (x <= n && !vis[x]) {
            vis[x] = 1;
        }
        else b.push_back(x);
    }
    ranges::sort(b);
    int ans = 0,j = 0;
    for (int i = 1;i <= n;i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            auto it = ranges::lower_bound(b.begin() + j,b.end(),2 * i + 1);
            if (it == b.end())
            {
                cout << -1 << endl;
                return ;
            }
            j = it - b.begin() + 1;
            ans++;
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