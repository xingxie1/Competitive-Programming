#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;y1--;x2--;y2--;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    pqueue<pii,vpii,greater<>> pq;
    pq.push({0,x1 * m + y1});
    vvt dis(n,vt(m,INT_MAX / 2));
    dis[x1][y1] = 0;
    while (!pq.empty()) 
    {
        auto [d,id] = pq.top();
        pq.pop();
        int x = id / m,y = id % m;
        if (d > dis[x][y]) continue;
        if (x == x2 && y == y2)
        {
            cout << d << endl;
            return ;
        }
        for (int dx = -2;dx <= 2;dx++)
        {
            for (int dy = -2;dy <= 2;dy++)
            {
                int nx = dx + x,ny = dy + y;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#') continue;
                int nd = d + 1;
                if ((abs(dx) == 1 && dy == 0) || (abs(dy) == 1 && dx == 0))
                {
                    if (dis[nx][ny] > d) 
                    {
                        dis[nx][ny] = d;
                        pq.push({d,nx * m + ny});
                    }
                }
                else if (dis[nx][ny] > nd) 
                {
                    dis[nx][ny] = nd;
                    pq.push({nd,nx * m + ny});
                }
            }
        }
    }
    cout << -1 << endl;
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