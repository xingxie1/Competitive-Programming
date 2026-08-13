#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int MOD = 998244353;
// const int MOD = (int)1e9+7;

ll dfs(int i,int t,int d,int x)
{
    if (i == 0) return t == 0 && x == 0;
    if (d == 1) return dfs(i - 1,t - 1,0,x - 1) + dfs(i - 1,t,1,x);
    else return dfs(i - 1,t,0,x - 1) + dfs(i - 1,t - 1,1,x);
}
void solve()
{
    int n,x,t;
    cin >> n >> x >> t;
    ll ans = dfs(n,t,0,x) + dfs(n,t,1,x);
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