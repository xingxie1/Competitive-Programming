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
    vll pre(n + 1),mx(n + 1);
    for (int i = 0;i < n;i++) 
    {
        pre[i + 1] = pre[i] + a[i];
        mx[i + 1] = max(mx[i],1LL * a[i]);
    }
    while (q--)
    {
        int k;
        cin >> k;
        auto j = ranges::upper_bound(mx,k) - mx.begin();
        j--;
        cout << pre[j] << " ";
    }
    cout << endl;
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