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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    int L = 0,R = INT_MAX / 2;
    int p1 = -1,p2 = -1;
    for (int i = 0;i < n;i++)
    {
        int l = a[i].fi,r = a[i].se;
        if (l > L)
        {
            L = l;
            p1 = i;
        }
        if (r < R) 
        {
            R = r;
            p2 = i;
        }
    }
    int ans = 0;
    L = 0,R = INT_MAX / 2;
    for (int i = 0;i < n;i++)
    {
        int l = a[i].fi,r = a[i].se;
        if (i == p1) continue;
        L = max(L,l);
        R = min(R,r);
    }
    ans = max(ans,R - L);
    L = 0,R = INT_MAX / 2;
    for (int i = 0;i < n;i++)
    {
        int l = a[i].fi,r = a[i].se;
        if (i == p2) continue;
        L = max(L,l);
        R = min(R,r);
    }
    ans = max(ans,R - L);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}