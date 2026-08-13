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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = 0;
    int k = 450;
    for (int v = 1;v <= k;v++)
    {
        for (int j = 0;j < n;j++)
        {
            ll i = j - 1LL * v * a[j];
            if (i >= 0 && i < n && a[i] == v) ans++;
        }
        for (int i = 0;i < n;i++)
        {
            if (a[i] <= k) continue;
            ll j = i + 1LL * a[i] * v;
            if (j < n && j >= 0 && a[j] == v) ans++;
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