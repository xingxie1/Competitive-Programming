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
    int n,r;
    cin >> n>> r;
    vt a(n);
    for (int i = 0;i < r;i++) a[i] = INT_MIN / 3;
    for (int i = r;i < n;i++)
    {
        a[i] = 1;
    }
    if (r == 0) a[n - 1] = INT_MIN / 3;
    for (int x : a) cout << x << " ";
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