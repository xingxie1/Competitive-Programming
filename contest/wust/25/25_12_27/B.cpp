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
    int n,L;
    cin >> n >> L;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    double ans = 0.0;
    int starti = 0,endi = 0;
    int sum = 0;
    for (int i = 0;i < n;i++)
    {
        sum += a[i];
        if (i + 1 >= L)
        {
            int len = i + 1;
            if (1.0 * sum / len > ans)
            {
                ans = 1.0 * sum / len;
                endi = i;
            }
        }
    }

    for (int i = 1;i < n;i++)
    {
        sum -= a[i - 1];
        starti = i;
        while (endi < n - 1 && endi - starti + 1 < L)
        {
            endi++;
            sum += a[endi];
        }
        int len = endi - starti + 1;
        ans = max(ans,sum * 1.0 / (len));
    }
    
    cout << ans << endl;
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