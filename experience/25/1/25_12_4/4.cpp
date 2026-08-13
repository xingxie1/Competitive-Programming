#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,L,a;
    cin >> n >> L >> a;
    int ans = 0;
    int last_t = 0,last_l = 0;
    for (int i = 0;i < n;i++)
    {
        int t,l;
        cin >> t >> l;
        if (i == 0)
        {
            ans += t / a;
            last_t = t;
            last_l = l;
        }
        else 
        {
            ans += (t - last_t - last_l) / a;
            last_t = t;
            last_l = l;
        }

    }
    ans += (L - last_t - last_l) / a;
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