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
    if ((n & (n - 1)) == 0) 
    {
        cout << -1 << endl;
        return ;
    }
    a[n - 1] = 1;
    ll sum = 1LL * n * (n + 1) / 2 - 1;
    for (int i = n - 1;i >= 2;i--)
    {
        a[i - 1] = i ^ 1;
        sum -= a[i - 1];
    }
    a[0] = sum;
    if (n % 2 == 0)
    {
        int x = a[0];
        int t = x & -x;
        for (int i = 1;i < n;i++)
        {
            if (a[i] == t)
            {
                swap(a[0],a[i]);
                break;
            }
        }
    }
    for (int x : a) cout << x << " " ;
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