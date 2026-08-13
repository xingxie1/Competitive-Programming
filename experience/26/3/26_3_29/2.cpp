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

class Unionfind
{
    vector<int> fa; 
public:
    int cc;
    Unionfind (int n) 
    {
        fa.resize(n);
        ranges::iota(fa,0);
        cc = n;
    }
    int find(int x)
    {
        if (x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }
    bool merge(int from,int to)
    {
        int x = find(from),y = find(to);
        if (x == y)
        {
            return false;
        }
        fa[x] = y;
        cc--;
        return true;
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vvt a(m,vt(n));
    for (int i = 0;i < m;i++)
    {
        for (int j = 0;j < n;j++) 
        {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int cnt =0 ;
    for (int x = 0;x < n;x++)
    {
        Unionfind uf(n);
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if (a[i][j] == x)
                {
                    if (j - 1 >= 0) uf.merge(a[i][j],a[i][j - 1]);
                    if (j + 1 < n) uf.merge(a[i][j],a[i][j + 1]);
                }
            }
        }
        // cout << n - uf.cc - 1 << endl;
        cnt += uf.cc - 1;
    }
    cout << cnt / 2 << endl;
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