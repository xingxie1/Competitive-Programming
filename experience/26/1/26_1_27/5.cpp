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
    if (n == 1)
    {
        cout << 1  << endl;
    }
    else if (n & 1) cout << -1 << endl;
    else 
    {
        int o = 1,e = n;
        vt a(n);
        for (int i = 0;i < n;i++)
        {
            if (i % 2 == 0)
            {
                a[i] = e;
                e -= 2;
            }
            else 
            {
                a[i] = o;
                o += 2;
            }
        }
        for (int x : a) cout << x << " ";
        cout << endl;
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