#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vpii b(n);
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        int cnt = 0;
        while (x % 2 == 0)
        {
            x /= 2;
            cnt++;
        }
        b[i].fi = cnt;
        cnt = 0;
        while (x % 5 == 0)
        {
            x /= 5;
            cnt++;
        }
        b[i].se = cnt;
    }
    auto cal = [&](int t)
    {
        int l = 0,r = 0;
        ll c1 = 0,c2 = 0;
        ll ans = 0;
        while (r < n)
        {
            c1 += b[r].fi;
            c2 += b[r].se;
            while (l <= r && min(c1,c2) >= t) 
            {
                ans += n - r;
                c1 -= b[l].fi;
                c2 -= b[l].se;
                l++;
            }
            r++;
        }
        return ans;
    };
    ll ans = cal(k) - cal(k + 1);
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