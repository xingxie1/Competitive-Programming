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
    vvll pre(n + 1,vll(m + 1));
    vvll h(n + 1,vll(m + 1)),v(n + 1,vll(m + 1));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            if (j + 1 < m && a[i][j] == '.' && a[i][j + 1] == '.') h[i + 1][j + 1] = 1;
            if (i + 1 < n && a[i][j] == '.' && a[i + 1][j] == '.') v[i + 1][j + 1] = 1; 
        }
    }
    auto f = [&](vvll& pre)
    {
        for (int i = 0;i < n;i++) 
        {
            for (int j = 0;j < m;j++) 
            {
                pre[i + 1][j + 1] += pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
            }
        }
    };
    f(h);
    f(v);
    auto query = [&](vvll& pre,int x1,int y1,int x2,int y2)
    {
        return pre[x2 + 1][y2 + 1] - pre[x2 + 1][y1] - pre[x1][y2 + 1] + pre[x1][y1];
    };
    int q;
    cin >> q;
    while (q--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;x2--;y1--;y2--;
        ll ans = 0;
        ans += query(h,x1,y1,x2,y2 - 1);
        ans += query(v,x1,y1,x2 - 1,y2);
        cout << ans << endl;
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