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
    if (n <= 2)
    {
        cout << -1 << endl;
        return ;
    }
    vt a(n);
    if (n & 1)
    {
        for (int i = 0;i < n - 1;i++) a[i] = i + 2;
        a[n - 1] = 1;
    }
    else 
    {
        for (int i = 0;i < n - 1;i++) a[i] = i + 2;
        a[0] = 3;
        a[1] = 1;
        a[n - 1] = 2;
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