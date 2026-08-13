#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i + 1 < n; i++)
    {
        for (int j = 0; j + 1 < m; j++)
        {
            int cnt = 0;
            cnt += a[i][j] == '1';
            cnt += a[i + 1][j] == '1';
            cnt += a[i][j + 1] == '1';
            cnt += a[i + 1][j + 1] == '1';

            if (cnt == 3)
            {
                NO;
                return;
            }
        }
    }

    YES;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}