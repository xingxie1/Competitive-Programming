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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
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
    ll n,k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll l = 0,r = LLONG_MAX / 2;
    auto check = [&](ll mn)
    {
        ll cnt = 0;
        for (int i = 0;i < n;i++) 
        {
            if (a[i] >= mn) continue;
            cnt += 1LL * (mn - a[i] + i) / (i + 1);
            if (cnt > k) return false;
        }
        return cnt <= k;
    };  
    while (l + 1 < r) 
    {
        ll m = l + r >> 1;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << endl;
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