#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

//x-2,y-1  x-2,y+1  x-1,y+2  x+1,y+2  x+2,y+1  x+2,y-1  x+1,y-2  x-1,y-2

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<pair<int,int>> ans;
    vector<int> dx = {-2,-2,-1,1,2,2,1,-1};
    vector<int> dy = {-1,1,2,2,1,-1,-2,-2};
    int d = abs(x1 - x2) + abs(y1 - y2);
    if (d <= 3) {}
    else if (d > 3 * k)
    {
        cout << "No" << endl;
        return ;
    }
    else if (d % 3 == 0)
    {
        int b = d / 3;
        if ((k - b) % 2)
        {
            cout << "No" << endl;
            return ;
        }
    }
    else if (d % 3 == 2)
    {
        int b = d / 3;
        if ((k - b) % 2) 
        {
            cout << "No" << endl;
            return ;
        }
    }
    else if (d % 3 == 1)
    {
        int b = d / 3;
        if ((k - b) % 3 != 0) cout << "No" << endl;
        return ;
    }
    cout << "Yes" << endl;
    while (1)
    {
        if (d <= 3) break;
        for (int ddx : dx)
        {
            int d1 = d;
            for (int ddy : dy)
            {
                int nx = x1 + ddx,ny = y1 + ddy;
                int nd = abs (nx - x2) + abs(ny - y2);
                if (nd < d && nx >= 1 && nx <= n && ny >= 1 && ny <= m) 
                {
                    ans.push_back({nx,ny});
                    x1 = nx,y1 = ny;
                    d = nd;
                    break;
                }
            }
            if (d < d1) break;
        }
    }
    if (d == 1)
    {
        for (int ddx : dx)
        {
            int d1 = d;
            for (int ddy : dy)
            {
                int nx = x1 + ddx,ny = y1 + ddy;
                int nd = abs (nx - x2) + abs(ny - y2);
                if (nd == 2 && nx >= 1 && nx <= n && ny >= 1 && ny <= m) 
                {
                    ans.push_back({nx,ny});
                    x1 = nx,y1 = ny;
                    d = nd;
                    break;
                }
            }
            if (d == 2) break;
        }
    }
    if (d == 2)
    {
        for (int ddx : dx)
        {
            int d1 = d;
            for (int ddy : dy)
            {
                int nx = x1 + ddx,ny = y1 + ddy;
                int nd = abs (nx - x2) + abs(ny - y2);
                if (nd == 3 && nx >= 1 && nx <= n && ny >= 1 && ny <= m) 
                {
                    ans.push_back({nx,ny});
                    x1 = nx,y1 = ny;
                    d = nd;
                    break;
                }
            }
            if (d == 3) break;
        }
    }
    if (d == 3)
    {
        ans.push_back({x2,y2});
    }
    while (ans.size() < k)
    {
        ans.push_back({x2+1,y2+1});
        ans.push_back({x2,y2});
    }
    for (int i = 0;i < k;i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
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