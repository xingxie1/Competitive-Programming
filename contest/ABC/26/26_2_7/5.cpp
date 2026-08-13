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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,d;
    cin >> n >> d;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int l = 0,r = 0;
    ll ans = 0;
    set<int> s;
    while (r < n)
    {
        while (l < r)
        {
            auto it = s.lower_bound(a[r] - d + 1);
            if (it != s.end() && *it < a[r] + d)
            {
                s.erase(a[l]);
                l++;
            }
            else break;
        }
        s.insert(a[r]);
        ans += (r - l + 1);
        r++;
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