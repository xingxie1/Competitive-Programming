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
    for (int i = 0;i < n;i++) cin >> a[i];
    int l = 0,r = n - 1,mn = 1,mx = n;
    while (l <= r)
    {
        if (a[l] == mn || a[r] == mn)
        {
            if (a[l] == mn) l++;
            else r--;
            mn++;
        }
        else if (a[l] == mx || a[r] == mx)
        {
            if (a[l] == mx) l++;
            else r--;
            mx--;
        }
        else break;
    }
    if (l > r ) cout << -1 << endl;
    else cout << l + 1 << " " << r + 1 << endl;
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