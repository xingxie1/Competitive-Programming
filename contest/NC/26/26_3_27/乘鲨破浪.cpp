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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vt a(n);
    vt b(n);
    vt vis(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) 
    {
        int x;
        cin >> x;
        x--;
        b[x] = 1;
        vis[x] = 1;
    }
    vvt g(n);
    vpii ans;
    for (int i = 0;i < n;i++)
    {
        if (b[i])
        {
            for (int j = 0;j < n;j++)
            {
                if (i == j) continue;
                int x = a[i],y = a[j];
                if (b[j])
                {
                    if (x % y != k && y % x != k)
                    {
                        g[i].push_back(j);
                        g[j].push_back(i);
                        continue;
                    }
                }
                if (vis[j]) continue;
                if (x % y != k && y % x != k)
                {
                    ans.push_back({i + 1,j + 1});
                    ans.push_back({i + 1,i + 1});
                    vis[j] = 1;
                }
            }
        }
    }

    for (int x : vis)
    {
        if (!x) 
        {
            cout << "NO" << endl;
            return ;
        }
    }
    if (m == 1)
    {
        int j = -1;
        for (int i = 0;i < n;i++)
        {
            if (b[i])
            {
                j = i;
                break;
            }
        }
        ans.push_back({j + 1,j + 1});
        cout << "YES" << endl; 
        cout << ans.size() << endl;
        for (auto& [l,r] : ans) cout << l << " " << r << endl;
        return ;
    }
    int j = -1;
    for (int i = 0;i < n;i++)
    {
        if (b[i] && g[i].size()) 
        {
            j = i;
            break;
        }
    }
    if (j == -1) 
    {
        cout << "NO" << endl;
        return ;
    }
    int x = g[j][0];
    ans.push_back({j + 1,x + 1});
    ans.push_back({j + 1,j + 1});
    for (int i = 0;i < n;i++)
    {
        if (b[i] && i != j && i != x)
        {
            ans.push_back({i + 1,i + 1});
            ans.push_back({x + 1,x + 1});

            ans.push_back({j + 1,x + 1});
            ans.push_back({j + 1,j + 1});
        }
    }
    ans.push_back({j + 1,j + 1});
    cout << "YES" << endl; 
    cout << ans.size() << endl;
    for (auto& [l,r] : ans) cout << l << " " << r << endl;

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