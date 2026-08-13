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
    int n,Ax,Ay,Bx,By;
    cin >> n >> Ax >> Ay >> Bx >> By;
    vt x(n),y(n);
    for (int i = 0;i < n;i++) cin >> x[i];
    for (int i = 0;i < n;i++) cin >> y[i];
    vt xs;
    for (int i = 0;i < n;i++) xs.push_back(x[i]);
    xs.push_back(Ax);
    xs.push_back(Bx);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    int m = xs.size();
    vector<pair<ll,ll>> pos(m,{LLONG_MAX,LLONG_MIN});//小大
    map<ll,vll> mp;
    for (int i = 0;i < n;i++)
    {
        mp[x[i]].push_back(y[i]);
    }
    mp[Ax].push_back(Ay);
    mp[Bx].push_back(By);

    for (int i = 0;i < m;i++)
    {
        for (ll v : mp[xs[i]]) 
        {
            pos[i].fi = min(pos[i].fi, v);
            pos[i].se = max(pos[i].se, v);
        }
    }
    vector dp(m + 1,vector<ll>(2,0));
    for (int i = 1;i < m;i++)
    {
        ll sum = pos[i].se - pos[i].fi;
        dp[i + 1][0] = min(dp[i][1] + abs(pos[i - 1].se - pos[i].se), dp[i][0] + abs(pos[i - 1].fi - pos[i].se)) + sum;
        dp[i + 1][1] = min(dp[i][1] + abs(pos[i - 1].se - pos[i].fi), dp[i][0] + abs(pos[i - 1].fi - pos[i].fi)) + sum;
    }
    ll ans = Bx - Ax + min(dp[m][0],dp[m][1]);
    cout << ans << endl;
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