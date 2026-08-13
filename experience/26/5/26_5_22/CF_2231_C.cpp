#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    umap<int,pair<int,ll>> cnt;
    cnt.reserve(n * 70);
    ll ans = LLONG_MAX;
    for (int x : a) 
    {
        int c = 0,f2 = 0,f1 = 0;
        while (1) 
        {
            if (x == 2 && f2) break;
            else if (x == 2) f2 = 1; 
            if (x == 1 && f1) break;
            else if (x == 1) f1 = 1;
            cnt[x].fi ++;
            cnt[x].se += c++;
            if (cnt[x].fi == n) ans = min(ans,cnt[x].se);
            if (x % 2) x++;
            else x /= 2;
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