// https://codeforces.com/problemset/problem/1511/C
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
    vt d(51);
    for (int i = n - 1;i >= 0;i--)
    {
        d[a[i]] = i + 1;
    }
    while (q--)
    {
        int t;
        cin >> t;
        cout << d[t] << " ";
        for (int& x : d)
        {
            if (x < d[t]) x++;
        }
        d[t] = 1;
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