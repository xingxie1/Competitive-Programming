#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
using vt = vector<int>;
using vvc = vector<vector<char>>;

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'

char rev(char c)
{
    return c == 'R' ? 'B' : 'R';
}

void solve()
{
    int n,m;
    ll k;
    cin >> n >> m >> k;

    ll mn = n + m - 2;

    if (k < mn || ((k - mn) & 1))
    {
        NO;
        return ;
    }

    vvc h(n,vector<char>(m - 1,'R')); // 横边
    vvc v(n - 1,vector<char>(m,'R')); // 竖边

    ll extra = k - mn;

    if (extra % 4 == 0)
    {
        // 先在左上角绕 4 步环若干次，再走最短路

        for (int j = 0;j < m - 1;j++)
        {
            h[0][j] = (j % 2 == 0 ? 'R' : 'B');
        }

        h[1][0] = 'R';
        v[0][0] = 'B';
        v[0][1] = 'B';

        char last = h[0][m - 2];

        for (int i = 0;i < n - 1;i++)
        {
            if (i % 2 == 0) v[i][m - 1] = rev(last);
            else v[i][m - 1] = last;
        }
    }
    else
    {
        // extra % 4 == 2
        // 先用 3 步从 (1,1) 绕到 (1,2)，相当于多走 2 步

        v[0][0] = 'R';
        h[1][0] = 'B';
        v[0][1] = 'R';

        for (int j = 1;j < m - 1;j++)
        {
            h[0][j] = (j % 2 == 1 ? 'B' : 'R');
        }

        h[1][1] = 'B';
        v[0][2] = 'R';

        char last = h[0][m - 2];

        for (int i = 0;i < n - 1;i++)
        {
            if (i % 2 == 0) v[i][m - 1] = rev(last);
            else v[i][m - 1] = last;
        }
    }

    YES;

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m - 1;j++)
        {
            cout << h[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0;i < n - 1;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_--) solve();

    return 0;
}