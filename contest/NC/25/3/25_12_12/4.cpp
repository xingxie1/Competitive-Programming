#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int a;
    cin >> a;
    queue<tuple<int,int,int>> q;
    q.emplace(a,0,0);
    umap<int,int> vis;
    umap<int,int> ans;
    int s = 9;
    for (int i = 1;i <= 8;i++)
    {
        ans[s]++;
        s = s * 10 + 9;
    }
    while (!q.empty())
    {
        auto [x,d,flag] = q.front();
        if(ans.count(x)) break;
        q.pop();
        vis[x] ++;
        if (flag == 0) 
        {
            int y = 9 * x;
            if (!vis.count(y)) 
            {
                q.emplace(y,d + 1,1);
            }
        }
        int y = x + 9;
        if (!vis.count(y))
        {
            q.emplace(y,d + 1,flag);
        }
    }
    
    if (!q.empty())
    {
        auto [x,d,flag] = q.front();
        cout << d << endl;
    }
    else cout << -1 << endl;
    
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