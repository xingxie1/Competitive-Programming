#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using vvt = vector<vector<int>>;
using vvvt = vector<vector<vector<int>>>;
using vvll = vector<vector<ll>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
using vvpii = vector<vector<pair<int,int>>>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0;i < n;i++) cin >> s[i];
    vvt vis(n,vt(m));
    vvt d = {{-1,0},{1,0},{0,-1},{0,1}};
    vvvt a;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            if (s[i][j] == 'O' || vis[i][j]) continue;
            vis[i][j] = 1;
            queue<pii> q;
            vpii c;
            q.push({i,j});
            int mnx = i,mxx = i,mny = j,mxy = j;
            while (!q.empty()) 
            {
                auto [x,y] = q.front();
                q.pop();
                c.push_back({x,y});
                for (int ii = 0;ii < 4;ii++)
                {
                    int nx = x + d[ii][0],ny = y + d[ii][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || s[nx][ny] == 'O') continue;
                    vis[nx][ny] = 1;
                    mnx = min(mnx,nx);
                    mxx = max(mxx,nx);
                    mny = min(mny,ny);
                    mxy = max(mxy,ny);
                    q.push({nx,ny});
                }
            }
            // cout << mnx << " " << mxx << " " << mny << " " << mxy << endl;
            vvt b(mxx - mnx + 2,vt(mxy - mny + 2));
            for (auto& [x,y] : c) 
            {
                // cout << x - mnx << " " << y - mny << endl;
                b[x - mnx][y - mny] = 1;
            //     // cout << b[x - mnx][y - mny] << endl;
            }
            a.push_back(b);
        }   
    }
    int N = a.size();
    if (N == 1) 
    {
        int i = 0,c1 = 0;
        for (int x1 = 0;x1 < a[i].size();x1++)
        {
            for(int y1 = 0;y1 < a[i][x1].size();y1++)
            {
                c1 += a[i][x1][y1];
            }
        }
        cout << c1 << endl;
        return ;
    }
    int ans = 0;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++) 
        {
            if (i == j) continue;
            int c1 = 0,c2 = 0;
            for (int x1 = 0;x1 < a[i].size();x1++)
            {
                for(int y1 = 0;y1 < a[i][x1].size();y1++)
                {
                    c1 += a[i][x1][y1];
                }
            }
            for (int x1 = 0;x1 < a[j].size();x1++)
            {
                for(int y1 = 0;y1 < a[j][x1].size();y1++)
                {
                    c2 += a[j][x1][y1];
                }
            }
            // if (c1 == 1) continue;
            // cout << c1 << " " << c2 << endl;
            int fff = 0;
            for (int x1 = 0;x1 < a[i].size();x1++)
            {
                for(int y1 = 0;y1 < a[i][x1].size();y1++)
                {
                    if (a[i][x1][y1] == 0) continue;
                    int ff = 1;
                    for (int x2 = 0;x2 < a[j].size();x2++)
                    {
                        for (int y2 = 0;y2 < a[j][x2].size();y2++)
                        {
                            if (a[j][x2][y2] == 0) continue;
                            int f = 1;
                            int dx = x2 - x1,dy = y2 - y1;
                            for (int x3 = 0;x3 < a[i].size();x3++)
                            {
                                if (x3 + dx >= a[j].size()) break;
                                for (int y3 = 0;y3 < a[i][x3].size();y3++)
                                {
                                    if (y3 + dy >= a[j][x3].size()) break;
                                    if (a[i][x 3][y3] == 0) continue;
                                    if (a[j][x3 + dx][y3 + dy] == 0)
                                    {
                                        f = 0;
                                        break;
                                    }
                                }
                            }
                            if (f) 
                            {
                                ff = 0;
                            }
                        }
                    }
                    if (ff == 0)
                    {
                        // cout << i << " " << j << " " << c1 << endl;
                        ans += c1;
                        fff = 1;
                    }
                    break;
                }
                if (fff) break;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

}