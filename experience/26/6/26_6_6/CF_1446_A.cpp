#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
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
    ll n,w;
    cin >> n >> w;
    vpii a(n);
    int j = -1;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].fi;
        a[i].se = i;
        if (a[i].fi >= (w + 1) / 2 && a[i].fi <= w) 
        {
            j = i;
        }
    }
    if (j != -1 ) 
    {
        cout << 1 << endl << j + 1 << endl;
        return;
    }
    vt ans;
    ranges::sort(a);
    if (a[0].fi > w) 
    {
        cout << -1 << endl;
        return ;
    }
    ll s = 0;
    for (int i = n - 1;i >= 0;i--)
    {
        if (s + a[i].fi > w) continue; 
        s += a[i].fi;
        ans.push_back(a[i].se);
    }
    if (s < (w + 1) / 2 || s > w) 
    {
        cout << -1 << endl;
        return ;
    }
    cout << ans.size() << endl;
    for (auto& x : ans) cout << x + 1 << " "; 
    cout << endl;
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