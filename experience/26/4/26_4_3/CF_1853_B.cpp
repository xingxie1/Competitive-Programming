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
    vpii a = {{1,0},{0,1}};
    ll s1 = 1,s2 = 1;
    for (int i = 3;;i++)
    {
        ll s = s1 + s2;
        if (s2 > n) 
        {
            break;
        }
        a.push_back({s1,s2});
        s1 = s2;
        s2 = s;
    }
    if (k > a.size()) 
    {
        cout << 0 << endl;
        return ;
    }
    // for (auto& [l,r] : a) cout << l << " " << r << endl;
    ll ans = 0;
    int x = a[k - 1].fi,y = a[k - 1].se;
    for (int i = 0;;i++)
    {
        if (1LL * i * x > n) break;
        if ((n - i * x) % y == 0) 
        {
            int j = (n - i * x) / y;
            if (j >= i) ans++;
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