#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int mod = (int)1e9 + 7;
void solve()
{
    int n,m,h;
    cin >> n >> m >> h;
    long long sum = 0;
    vector<long long> r(n + 1),c(m + 1);
    vector<vector<long long>> hh(n + 1,vector<long long>(m + 1));
    for (int i = 0;i < h;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        r[x] += z;
        c[y] += z;
        hh[x][y] += z;
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            sum += (r[i] + c[j] - hh[i][j]) * (i + j);
            sum %= mod;
        }
    }
    cout << sum;
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