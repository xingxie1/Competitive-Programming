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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    vvt g(m);
    vt cnt(n);
    vt ans(m,-1);
    for (int i = 0;i < m;i++) 
    {
        int k;
        cin >> k;
        for (int j = 0;j < k;j++)
        {
            int x;
            cin >> x;
            x--;
            g[i].push_back(x);
        }
        if (g[i].size() == 1)
        {
            ans[i] = g[i][0];
            cnt[g[i][0]]++;
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (cnt[i] > (m + 1) / 2) 
        {
            NO;
            return ;
        }
    }
    for (int i = 0;i < m;i++)
    {
        if (ans[i] != -1) continue;
        int x = g[i][0],y = g[i][1];
        if (cnt[x] < cnt[y]) 
        {
            ans[i] = x;
            cnt[x]++;
        } 
        else 
        {
            ans[i] = y;
            cnt[y]++;
        }
    }
    YES;
    for (int i = 0; i < m; i++) cout << ans[i] + 1 << " ";
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