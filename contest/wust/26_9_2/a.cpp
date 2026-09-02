#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> suf(n + 1,INT_MAX / 2);
    for (int i = 0;i < n;i++) cin >> a[i];
    int mx = 0;
    for (int i = n - 1;i >= 0;i--) suf[i] = min(suf[i + 1],a[i]);
    vt ans;
    for (int i = 0;i < n;i++)
    {
        if (a[i] > mx && a[i] < suf[i + 1]) ans.push_back(a[i]);
        mx = max(mx,a[i]); 
    }
    cout << ans.size() << " ";
    for (int i = 0;i < min((int)ans.size(),100);i++) cout << ans[i] << " ";

}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}