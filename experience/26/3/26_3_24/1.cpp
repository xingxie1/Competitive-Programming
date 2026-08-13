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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    queue<pii> q;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '#') q.push({i,j});
        }
    }
    if (q.size() == 0)
    {
        cout << "Blue" << endl;
        return ;
    }
    vvt dd = {{-1,0},{1,0},{0,-1},{0,1}};
    while (!q.empty())
    {
        auto[x,y] = q.front();
        q.pop();
        for (int i = 0;i < 4;i++)
        {
            int nx = x + dd[i][0],ny = y + dd[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == '.') a[nx][ny] = '#';
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (char c : a[i])
        {
            if (c == '.') 
            {
                cout << "Draw" << endl;
                return ;
            }
        }
    }
    cout << "Red" << endl;
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