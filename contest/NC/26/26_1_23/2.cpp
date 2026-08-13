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
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int x = 0,y = 0;
    for (int i = 0;i < n;i++)
    {
        x += a[i] * i;
        y += a[i];
    }
    int need = n - k;
    int lim = 1 << n;

    for (int s = 0; s < lim; s++) 
    {
        if (__builtin_popcount(s) != need) continue;
        ll p = 0, q = 0;
        for (int i = 0; i < n; i++) 
        {
            if (s >> i & 1) 
            {
                p += a[i] * i;
                q += a[i];
            }
        }
        if (x * q == p * y) 
        {
            cout << "Yes" << endl;
            return ;
        }
    }

    cout << "No" << endl;
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