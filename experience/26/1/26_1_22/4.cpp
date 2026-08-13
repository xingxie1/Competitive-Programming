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
    int n,x;
    cin >> n >> x;
    vt a(n);
    int n1 = x,n2 = 0;
    while (n1)
    {
        if (n1 % 2) n2 = n2 * 2 + 1;
        else break;
        n1 >>= 1;
    }
    // cout << n2 << endl;
    if (n2 >= n)
    {
        for (int i = 0;i < n;i++) a[i] = i;
        int s = 0;
        for (int i = 0;i < n;i++) s |= a[i];
        if (s != x) a[n - 1] = x;
    }
    else 
    {
        for (int i = 0;i <= n2;i++) a[i] = i;
        for (int i = n2 + 1;i < n;i++) a[i] = x;
        int s = 0;
        for (int i = 0;i < n;i++) s |= a[i];
        if (s != x) a[n - 1] = x;
    }
    for (int x : a) cout << x << " ";
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