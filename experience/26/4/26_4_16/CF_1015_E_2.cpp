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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt u(n,vt(m)),d(n,vt(m)),l(n,vt(m)),r(n,vt(m));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '*')
            {
                if (j == 0) l[i][j] = 1;
                else l[i][j] = l[i][j - 1] + 1;
                if (i == 0) u[i][j] = 1;
                else u[i][j] = u[i - 1][j] + 1;
            }
        }
    }
    for (int i = n - 1;i >= 0;i--)
    {
        for (int j = m - 1;j >= 0;j--)
        {
            if (a[i][j] == '*')
            {
                if (j == m - 1) r[i][j] = 1;
                else r[i][j] = r[i][j + 1] + 1;
                if (i == n - 1) d[i][j] = 1;
                else d[i][j] = d[i + 1][j] + 1;
            }
        }
    }
    vvt ans;
    vvt row(n,vt(m + 1)) ,col(m,vt(n + 1));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '*')
            {
                int len = min({r[i][j],l[i][j],u[i][j],d[i][j]}) - 1;
                if (len < 1) continue;
                ans.push_back({i + 1,j + 1,len});
                row[i][j - len]++;
                row[i][j + len + 1]--;
                col[j][i - len]++;
                col[j][i + len + 1]--;
            }
        }
    }
    vvt vis(n,vt(m));
    for (int i = 0;i < n;i++)
    {
        int sum = 0;
        for (int j = 0;j < m;j++) 
        {
            sum += row[i][j];
            if(sum) vis[i][j] = 1;
        }
    }
    for (int j = 0;j < m;j++)
    {
        int sum = 0;
        for (int i = 0;i < n;i++)
        {
            sum += col[j][i];
            if (sum) vis[i][j] = 1;
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '*' && !vis[i][j]) 
            {
                cout << -1 << endl;
                return ;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto& g  :ans) 
    {
        for (int x : g) cout << x << " ";
        cout << endl;
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