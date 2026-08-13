#include<bits/stdc++.h>
using namespace std;

int N = 5000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,m,c;
    cin >> n >> m >> c; 
    vector<vector<long long>> s(n+1,vector<long long>(m+1));
    long long mx = LLONG_MIN,mxi = 0,mxj = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            int v;
            cin >> v;
            s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + v;
        }
    }
    for (int i = 0;i <= n-c;i++)
    {
        for (int j = 0;j <= m-c;j++)
        {
            long long x = s[i+c][j+c] - s[i+c][j] - s[i][j+c] + s[i][j];
            if (x > mx)
            {
                mx = x;
                mxi = i;
                mxj = j;
            }
        }
    }
    cout << mxi +1 << " " << mxj + 1;
    

    return 0;
}

