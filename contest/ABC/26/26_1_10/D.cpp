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
    int n,q;
    cin >> n >> q;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    while (q--)
    {
        int x,y;
        cin >> x >> y;
        auto pos = lower_bound(a.begin(),a.end(),x) - a.begin();
        int l = pos - 1,r = n;
        while (l + 1 < r)
        {
            int mid = (r + l) / 2;
            if (a[mid] - x + 1 - (mid - pos + 1) >= y) r = mid;
            else l = mid;
        }
        cout << a[l] + y - (a[l] - x + 1 - (l - pos + 1)) << endl;
    }
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