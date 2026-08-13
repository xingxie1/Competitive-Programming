#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
    int n,k;
    cin >> n >> k;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    map<int,vt> p;
    for (int i = 1;i <= n;i++) 
    {
        p[a[i]].push_back(i);
    }
    int ans = INT_MAX;
    for (auto& [x,b] : p) 
    {
        int mx1 = 0,mx2 = 0;
        int last = 0;
        for (int i : b) 
        {
            int d = i - last - 1;
            last = i;
            if (d >= mx1) 
            {
                mx2 = mx1;
                mx1 = d;
            }
            else if (d > mx2) 
            {
                mx2 = d;
            }
        }
        if (b.empty()) continue;
        int d = n - last;
        if (d >= mx1) 
        {
            mx2 = mx1;
            mx1 = d;
        }
        else if (d > mx2) 
        {
            mx2 = d;
        }
        ans = min(ans,max(mx1 / 2,mx2));
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