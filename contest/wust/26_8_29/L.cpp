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
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vvt a(n,vt(3));
    for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];    
    ranges::sort(a,{},[&](auto& b) {
        return -b[2];
    });
    ll ans = 0,sum = 0;
    queue<pll> q;
    for (int i = 0;i < n;i++) 
    {   
        ll c = a[i][0],w = a[i][1],f = a[i][2];
        // cout << c << " " << w << " " << f << endl;
        w *= c;
        ans += w / k * f;
        ll res = w % k;
        sum += res;
        if (res > 0) q.push({res,f});
        ll s = 0,mx = 0;
        while (sum >= k && !q.empty())
        {
            s += q.front().fi;
            ll ff = q.front().se;
            q.pop();
            mx = max(mx,ff);
            if (s >= k) 
            {
                ans += s / k * mx;
                sum -= s / k * k;
                s %= k;
                mx = 0;
                if (s > 0) q.push({s,ff});
            }
        }
    }
    ll mx = 0;
    while (!q.empty())
    {
        ll ff = q.front().se;
        q.pop();
        mx = max(mx,ff);
    }
    ans += mx;
    cout << ans << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

}