#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using vvt = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;

void solve()
{
    int n,w,k;
    cin >> n >> w >> k;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    // vvll suf(n + 1,vll(w + 1));
    // for (int i = n - 1;i >= 0;i--) 
    // {
    //     for (int x = w;x >= 0;x--) 
    //     {
    //         suf[i][x] = max(suf[i][x],suf[i + 1][x]);
    //         if (x >= a[i].fi) suf[i][x] = max(suf[i][x],suf[i + 1][x - a[i].fi] + a[i].se);
    //     }
    // }
    // ll mx = suf[0][w];
    // vll pre(w + 1);
    // vt tmp;
    // for (int i = 0;i < n;i++) 
    // {
    //     vll npre = pre;
    //     for (int j = w;j >= a[i].fi;j--)
    //     {
    //         npre[j] = max(npre[j],pre[j - a[i].fi] + a[i].se);
    //     }
    //     ll mm = 0;
    //     for (int j = 0;j <= w;j++)
    //     {
    //         mm = max(mm,pre[j] + suf[i + 1][w - j]);
    //     }
    //     if (mm == mx) 
    //     {
    //         tmp.push_back(a[i].se);
    //     }
    //     pre = npre;
    // }
    // ranges::sort(tmp);
    // int m = tmp.size();
    // ll ans = mx;
    // for (int i = m - 1;i >= 0;i--) 
    // {
    //     if (!k) break;
    //     k--;
    //     ans += tmp[i];
    //     // cout << tmp[i] << " " << endl;
    // }
    // cout << ans << endl;

}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

}