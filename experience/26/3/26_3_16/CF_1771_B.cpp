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
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<set<int>> a(n);
    for (int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        a[x].insert(y);
        a[y].insert(x);
    }
    int l = 0,r = 0;
    ll ans = 0;
    while (r < n)
    {
        int mx = -1;
        if (!a[r].empty())
        {
            auto it = a[r].lower_bound(r);
            if (it != a[r].begin()) mx = *(--it);
        }
        while (l <= mx) l++;
        ans += r - l + 1;
        r++;
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