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
    int n,m;
    cin >> n >> m;
    vt cnt(m + 1),size(m + 1);
    for (int i = 0;i < n;i++) 
    {
        int x,y;
        cin >> x >> y;
        cnt[x]++;
        size[x] += y;
    }

    for (int i = 1;i <= m;i++)
    {
        double ans = size[i] * 1.0 / cnt[i];
        cout << ans << endl;
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