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
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
    }
    int ans = unique(a.begin(), a.end()) - a.begin();
    n = ans;
    for (int i = 0;i < n - 2;i++) 
    {
        ans -= (a[i] < a[i + 1] && a[i + 1] < a[i + 2]);
        ans -= (a[i] > a[i + 1] && a[i + 1] > a[i + 2]);
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