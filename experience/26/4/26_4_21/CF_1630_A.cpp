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
    int n,k;
    cin >> n >> k;
    vt vis(n);
    vpii ans;
    if (k == 0)
    {
        for (int i = 0;i < n / 2;i++)
        {
            ans.push_back({i,n - 1 - i}); 
        }
    }
    else if (k == n - 1)
    {
        if (n == 4) 
        {
            cout << -1 << endl;
            return ;
        }
        ans.push_back({n - 1,n - 2});
        ans.push_back({1,3});
        ans.push_back({0,n - 4});
        vis[0] = vis[1] = vis[3] = 1;
        vis[n - 1] = vis[n - 2] = vis[n - 4] = 1;
        for (int i = 2;i < n / 2;i++)
        {
            if (!vis[i]) ans.push_back({i,n - i - 1});
            vis[i] = 1;
        }
    }
    else 
    {
        ans.push_back({k,n - 1});
        ans.push_back({0,n - 1 - k});
        vis[n - 1 - k] = 1;
        vis[n - 1 ] = 1;
        vis[k] = 1;
        vis[0] = 1;
        for (int i = 0;i < n / 2;i++)
        {
            if (!vis[i]) ans.push_back({i,n - i - 1});
            vis[i] = 1;
        }
    }
    for (auto& [l,r] : ans) cout << l << " " << r << endl;
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