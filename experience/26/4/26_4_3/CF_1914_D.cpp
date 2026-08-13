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
    int n;
    cin >> n;
    vpii a(n),b(n),c(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi,a[i].se = i;
    for (int i = 0;i < n;i++) cin >> b[i].fi,b[i].se = i;
    for (int i = 0;i < n;i++) cin >> c[i].fi,c[i].se = i;
    ranges::sort(a,{},[&](auto& x){return -x.fi;});
    ranges::sort(b,{},[&](auto& x){return -x.fi;});
    ranges::sort(c,{},[&](auto& x){return -x.fi;});
    ll ans = 0;
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            for (int k = 0;k < 3;k++)
            {
                int ia = a[i].se,ib = b[j].se,ic = c[k].se;
                if (ia != ib && ia != ic && ib != ic)
                {
                    ans = max(ans,1LL * a[i].fi + b[j].fi + c[k].fi);
                }
            }
        }
    }
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