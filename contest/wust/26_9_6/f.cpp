#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n);
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++)  
        {
            int x;
            cin >> x;
            a[i] += x;
        }
    }
    int ans = 0;
    int last = 0;
    for (int i = 0;i < n;i++)
    {
        if (a[i] < last) ans++;
        last = a[i];
    }
    cout << ans << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}