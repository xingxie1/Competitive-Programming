#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector a(n,vector<int>(m));
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if ((i % 3 == 1 || n % 3 == 1 && i == n - 1) && (j % 3 == 1 || m % 3 == 1 && j == m - 1))
            {
                a[i][j] = 1;
                cnt++;
            }
        }
    }
    cnt = n * m - cnt;
    if (cnt < k)
    {
        cout << -1 << endl;
        return ;
    }
    for (int i = 0;i < n;i ++)
    {
        for (int j = 0;j < m;j ++)
        {
            if (cnt <= k) break;
            if (a[i][j] == 0)
            {
                cnt--;
                a[i][j] = 1;
            }
        }
    }

    for (int i = 0;i < n;i ++)
    {
        for (int j = 0;j < m;j ++)
        {
            cout << a[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}