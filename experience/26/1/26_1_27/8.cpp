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
    int ans = n;
    int m = bit_width((uint32_t) n);
    if (n % 2 == 0)
    {
        ans = (1 << m) - 1;
    }
    cout << ans << endl;
    if (n % 2 == 0)
    {
        if ((n & (n - 1)) == 0)
        {
            m--;
            a[n - 1] = 1 << m;
            a[n - 2] = a[n - 1] - 1;
            a[n - 3] = a[n - 2] - 1;
            int t = 4;
            a[0] = 2,a[1] = 1,a[2] = 3;
            for (int i = 3;i < n - 3;i++)
            {
                if (t == a[n - 3]) t += 3;
                a[i] = t++;
            }
        }
        else 
        {
            m--;
            a[n - 2] = 1 << m;
            a[n - 1] = a[n - 2] - 1;
            a[n - 3] = a[n - 2] + 1;
            int t = 1;
            for (int i = 0;i < n - 3;i++)
            {
                if (t == a[n - 1]) t += 3;
                a[i] = t++;
            }
        }
    }
    else 
    {
        int t = 4;
        for (int i = 3;i < n;i++)
        {
            a[i] = t++;
        }
        a[0] = 2,a[1] = 1,a[2] = 3;
    }
    int s = 0;
    for (int x : a) cout << x << " ";
    // for (int i = 0;i < n;i++)
    // {
    //     if (i % 2 == 0) s &= a[i];
    //     else s |= a[i];
    // }
    // cout << s << endl;
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