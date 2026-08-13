#include<bits/stdc++.h>
using namespace std;

int N = 5000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,m;
    cin >> n >> m;
    int mxx = 0;
    vector<vector<int>> a(N+1,vector<int>(N+1)),s(N+2,vector<int>(N+2));
    for (int i = 0;i < n;i++)
    {
        int x,y,v;
        cin >> x >> y >> v;
        a[x][y] += v;
        mxx = max({mxx,x,y});
    }
    int mx = 0;
    for (int i = 0;i <= mxx;i++)
    {
        for (int j = 0;j <= mxx;j++)
        {
            s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + a[i][j];
            if (i+1 >= m && j + 1 >= m)
            {
                int x = s[i+1][j+1] - s[i+1][j+1-m] - s[i+1-m][j+1] + s[i+1-m][j+1-m];
                mx = max(mx,x);
            }
        }
    }
    
    cout << mx << endl;

    

    return 0;
}