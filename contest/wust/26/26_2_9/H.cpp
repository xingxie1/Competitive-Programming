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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    vvt a(n,vt(m));
    vvll b(n,vll(m));
    vvt d = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1},{0,-2},{-2,0},{2,0},{0,2}};
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            cin >> a[i][j];
            b[i][j] += a[i][j];
        }
    }
    int mxx = 0,mxy = 0;
    ll mx = 0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            for (int k = 0;k < 12;k++)
            {
                int dx = d[k][0],dy = d[k][1];
                int x = i + dx,y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                b[i][j] += a[x][y];
            }
            if (b[i][j] > mx)
            {
                mxx = i;
                mxy = j;
                mx = b[i][j];
            }
        }
    }
//     for (int i = 0;i < n;i++)
//     {
//         for (int j = 0;j < m;j++) cout << b[i][j] << " ";
//         cout << endl;
//     }
    while (q--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x--,y--;
        b[x][y] += z;
        if (b[x][y] > mx)
        {
            mx = b[x][y];
            mxx = x;
            mxy = y;
        }
        for (int i = 0;i < 12;i++)
        {
            int dx = d[i][0],dy = d[i][1];
            int nx = x + dx,ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            b[nx][ny] += z;
            if (b[nx][ny] > mx)
            {
                mx = b[nx][ny];
                mxx = nx;
                mxy = ny;
            }
        }
        // cout << mx << endl;
        cout << mxx + 1 << " " << mxy + 1<< endl;
        // cout << "@@@" << endl;
        // for (int i = 0;i < n;i++)
        // {
        //     for (int j = 0;j < m;j++) cout << b[i][j] << " ";
        //     cout << endl;
        // }
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