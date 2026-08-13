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
    int n,k;
    cin >> n >> k;
    vpii p;
    for (int i = 0;i < n;i++) 
    {
        int l,r;
        cin >> l >> r;
        p.push_back({l - k,1});
        p.push_back({r + 1,-1});
    }
    ranges::sort(p);
    int ans = 0;
    int sum = 0;
    for (int i = 0;i < p.size();) 
    {
        int x = p[i].fi;
        while (i < p.size() && p[i].fi == x) 
        {
            sum += p[i].se;
            i++;
        }
        ans = max(ans,sum);
    }
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