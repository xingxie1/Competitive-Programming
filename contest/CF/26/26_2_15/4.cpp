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
    vll f(n + 1);
    for (int i = 1;i <= n;i++) cin >> f[i];
    vll a(n + 1);
    for (int i = 2;i <= n - 1;i++)
    {
        a[i] = (f[i - 1] + f[i + 1] - 2 * f[i]) / 2;
    }
    ll s = f[1];
    for (int i = 2;i < n;i++)
    {
        s -= (i - 1) * a[i];
    }
    a[n] = s / (n - 1);
    s = f[2];
    for (int i = 3;i <= n;i++)
    {
        s -= (i - 2) * a[i];
    }
    a[1] = s;
    for (int i = 1;i <= n;i++) cout << a[i] << " ";
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