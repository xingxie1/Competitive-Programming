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
    int n,m,k;
    cin >> n >> m >> k;
    int a = 0,b = 0;
    int ans = 0;
    int flag = 0;
    while (1)
    {
        int sum = a + b + max(a,b) - 1;
        if (sum > m) break;
        ans = a + b + 1;

        if (k == n && a == n - 1) break;
        if (k == 1 && b == n - 1) break;
        if (a == k - 1 && b == n - k) break;


        if (flag % 2 == 0 && a + 1 < k) a++;
        if (flag % 2 == 1 && b + 1 <= n - k) b++;
        flag ++;
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