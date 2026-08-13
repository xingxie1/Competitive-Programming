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
    int n,h;
    cin >> n >> h;
    vt t(n),l(n),r(n);
    for (int i = 0;i < n;i++) cin >> t[i] >> l[i] >> r[i];

    ll low = h,high = h;
    for (int i = 0;i < n;i++)
    {
        int dt;
        if (i == 0) dt = t[i];
        else dt = t[i] - t[i - 1];
        low -= dt;
        high += dt;
        low = max(low,1LL * l[i]);
        high = min(high,1LL * r[i]);
        if (low > high) 
        {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
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