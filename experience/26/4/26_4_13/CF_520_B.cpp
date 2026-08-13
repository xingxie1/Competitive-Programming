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
    int n,m;
    cin >> n >> m;
    queue<pii> q;
    q.push({n,0});
    vt vis(1e4 + 5);
    while (!q.empty())
    {
        auto [x,d] = q.front();
        q.pop();
        if (x == m) 
        {
            cout << d << endl;
            return ;
        }
        if (x * 2 <= 1e4 && !vis[x * 2]) 
        {
            q.push({x * 2,d + 1});
            vis[x * 2] = 1;
        }
        if (x - 1 > 0 && !vis[x - 1]) 
        {
            q.push({x - 1,d + 1});
            vis[x - 1] = 1;
        }
    }
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