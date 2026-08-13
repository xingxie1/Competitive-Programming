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
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    vll suf(n + 1);
    int mx = 0;
    for (int i = n - 1;i >= 0;i--)
    {
        mx = max({mx,a[i],b[i]});
        suf[i] = suf[i + 1] + mx;
    }
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        cout << suf[l - 1] - suf[r] << " ";
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