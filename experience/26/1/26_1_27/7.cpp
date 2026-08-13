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
    if (x == 0)
    {
        if (n == 1) cout << -1 << endl;
        else if (n % 2 == 0) cout << n << endl;
        else cout << n + 3 << endl;
    }
    else if (x == 1)
    {
        if (n & 1) cout << n << endl;
        else cout << n + 3 << endl;
    }
    else 
    {
        int m = __builtin_popcount(x);
        if (n <= m) cout << x << endl;
        else if ((n - m) % 2 == 0) cout << x + n - m << endl;
        else cout << x + n - m + 1 << endl;
    }

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