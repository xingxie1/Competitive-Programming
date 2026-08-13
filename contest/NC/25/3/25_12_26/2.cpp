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
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    for (int i = 1;i < n;i++)
    {
        if (a[i] - a[i - 1] >= 2)
        {
            int d = a[i] - a[i - 1];
            if (a[n - 1] - a[i] + d < 8) continue;
            int j = n - 1;
            while (i < j)
            {
                swap(a[i++],a[j--]);
            }
            break;
        }
    }
    int ans = 0;
    for (int x : a) cout << x << " ";
    for (int i = 1;i < n;i++) ans += min(abs(a[i] - a[i - 1]),8 - abs(a[i] - a[i - 1]));
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