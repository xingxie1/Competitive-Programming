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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vvt g(n + 1,vt());
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    map<int,int> cnt;
    for (int i = 1;i <= n;i++) cnt[g[i].size()]++;
    int x = 0,y = 0;
    if (cnt.size() == 3)
    {
        auto it = cnt.begin();
        while (it != cnt.end())
        {
            if (it->se == 1) x = it->fi;
            else y = it->fi - 1;
            it++;
        }
    }
    else if (cnt.size() == 2)
    {
        auto it = cnt.rbegin();
        x = it->fi;
        y = it->fi - 1;
    }
    cout << x << " " << y << endl;

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